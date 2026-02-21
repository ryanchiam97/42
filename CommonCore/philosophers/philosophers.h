/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 00:12:26 by rchiam            #+#    #+#             */
/*   Updated: 2026/02/22 00:01:37 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_shared_data	t_shared_data;

typedef struct s_philosopher
{
	int				id;
	pthread_t		thread;
	t_shared_data	*shared_data;

	pthread_mutex_t	*mtx_l_fork;
	pthread_mutex_t	*mtx_r_fork;

	long			last_meal_ms;
	long			meals_eaten;
	pthread_mutex_t	mtx_meals;
}					t_philosopher;

typedef struct s_shared_data
{
	int				n;
	long			time_to_die_ms;
	long			time_to_eat_ms;
	long			time_to_sleep_ms;
	int				must_eat;
	long			start_time;
	int				stop;

	pthread_mutex_t	*mtx_forks;
	pthread_mutex_t	mtx_print;
	pthread_mutex_t	mtx_stop_all;

	pthread_mutex_t	mtx_seat;
	int				seats;

	pthread_mutex_t	mtx_tickets;
	long			next_ticket;
	long			now_serving_ticket;

	t_philosopher	*p;
}					t_shared_data;

long	atolong(char *s);
int		is_all_digits(char *s);
int		parse_inputs(t_shared_data *c, int argc, char **argv);
int		init_shared_mutex(t_shared_data *shared_data);
void	init_philosopher(t_shared_data *sd, int i);
int		init(t_shared_data *sd);
void	clean_all(t_shared_data *sd);
long	now_ms(void);
void	mtx_print_line(t_philosopher *p, char *line);
void	mtx_stop_set(t_shared_data *sd);
int		mtx_stop_get(t_shared_data *sd);
void	one_philo_case(t_philosopher *p);
long	mtx_get_ticket(t_shared_data *sd);
void	wait_ticket_to_table(t_shared_data *sd, long my_ticket);
void	leave_table(t_shared_data *sd);
void	sleep_handle(t_philosopher *p, long time);
void	sleep_think(t_philosopher *p);
void	take_fork(t_philosopher *p);
void	eat(t_philosopher *p);
void	return_fork(t_philosopher *p);
void	*p_routine(void *arg);
long	last_mealtime_get(t_philosopher *p);
int		meals_get(t_philosopher *p);
void	handle_death(t_shared_data *sd, int id);
int		someone_died(t_shared_data *sd);
int		all_eaten(t_shared_data *sd);
void	*m_routine(void *arg);
int		launch_philos(t_shared_data *sd, int *count);
int		launch_monitor(t_shared_data *sd, pthread_t *monitor);
void	join_philos(t_shared_data *sd, int created);

#endif
