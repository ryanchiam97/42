/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuychen <yuychen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 21:32:43 by yuychen           #+#    #+#             */
/*   Updated: 2025/12/30 23:12:10 by yuychen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int					id;
	pthread_t			thread;
	t_data				*data;

	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;

	long				last_meal_ms;
	int					meals_eaten;
	pthread_mutex_t		meal_mtx;
}						t_philo;

typedef struct s_data
{
	int					n;
	long				t_die;
	long				t_eat;
	long				t_sleep;
	int					must_eat;

	long				start_ms;
	int					stop;
	int					seats;

	pthread_mutex_t		stop_mtx;
	pthread_mutex_t		print_mtx;
	pthread_mutex_t		*forks;
	pthread_mutex_t		seat_mtx;

	t_philo				*philos;
}						t_data;

int						parse_args(t_data *d, int ac, char **av);
int						init_all(t_data *d);

long					now_ms(void);
int						should_stop(t_data *d);
void					set_stop(t_data *d);

void					print_action(t_philo *p, const char *msg);
void					*philo_routine(void *arg);
void					clean_all(t_data *d);

void					die_and_stop(t_data *d, int id);
long					get_last_meal_ms(t_philo *p);
void					*monitor_routine(void *arg);

void					take_forks(t_philo *p);
void					*one_philo_case(t_philo *p);
void					eat(t_philo *p);
void					put_forks(t_philo *p);
void					sleep_and_think(t_philo *p);

void					smart_sleep(long ms, t_data *d);
void					wait_seat(t_data *d);
void					leave_seat(t_data *d);
#endif
