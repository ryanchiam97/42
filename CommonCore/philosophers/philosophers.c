/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 00:11:56 by rchiam            #+#    #+#             */
/*   Updated: 2026/02/22 00:04:36 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	atolong(char *s)
{
	long	n;
	long	i;

	i = 0;
	n = 0;
	while (s[i])
	{
		n = n * 10 + (s[i] - '0');
		i++;
	}
	return (n);
}

int	is_all_digits(char *s)
{
	int	i;

	if (!s || s[0] == '\0')
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	parse_inputs(t_shared_data *c, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (1);
	if (!isalldigits(argv[1]) || !isalldigits(argv[2])
		|| !isalldigits(argv[3]) || !isalldigits(argv[4]))
		return (1);
	c->n = (int)atolong(argv[1]);
	c->time_to_die_ms = atolong(argv[2]);
	c->time_to_eat_ms = atolong(argv[3]);
	c->time_to_sleep_ms = atolong(argv[4]);
	c->must_eat = -1;
	if (argc == 6)
	{
		if (!isalldigits(argv[4]))
			return (1);
		c->must_eat = (int)atolong(argv[5]);
	}
	if (c->n <= 0 || c->time_to_eat_ms <= 0 || c->time_to_die_ms <= 0
		|| c->time_to_sleep_ms <= 0)
		return (1);
	return (0);
}

int	init_shared_mutex(t_shared_data *shared_data)
{
	if (pthread_mutex_init(&(shared_data->mtx_stop_all), NULL) != 0)
		return (1);
	if (pthread_mutex_init(&(shared_data->mtx_print), NULL) != 0)
		return (1);
	if (pthread_mutex_init(&(shared_data->mtx_seat), NULL) != 0)
		return (1);
	if (pthread_mutex_init(&(shared_data->mtx_tickets), NULL) != 0)
		return (1);
	return (0);
}

void	init_philosopher(t_shared_data *sd, int i)
{
	sd->p[i].id = i + 1;
	sd->p[i].shared_data = sd;
	pthread_mutex_init(&sd->p[i].mtx_meals, NULL);
	sd->p[i].last_meal_ms = sd->start_time;
	sd->p[i].meals_eaten = 0;
	pthread_mutex_init(&sd->mtx_forks[i], NULL);
	sd->p[i].mtx_l_fork = &(sd->mtx_forks[i]);
	sd->p[i].mtx_r_fork = &(sd->mtx_forks[(i + 1) % sd->n]);
}

int	init(t_shared_data *sd)
{
	int	i;

	if (init_shared_mutex(sd) != 0)
		return (1);
	sd->mtx_forks = malloc(sizeof(pthread_mutex_t) * (sd->n));
	if (!sd->mtx_forks)
		return (1);
	sd->p = malloc(sizeof(t_philosopher) * (sd->n));
	if (!sd->p)
		return (1);
	i = 0;
	while (i < sd->n)
		init_philosopher(sd, i++);
	sd->seats = sd->n / 2;
	if (sd->seats < 1)
		sd->seats = 1;
	sd->next_ticket = 0;
	sd->now_serving_ticket = 0;
	sd->stop = 0;
	return (0);
}

void	clean_all(t_shared_data *sd)
{
	int	i;

	if (sd->mtx_forks)
	{
		i = 0;
		while (i < sd->n)
		{
			pthread_mutex_destroy(&sd->mtx_forks[i]);
			pthread_mutex_destroy(&sd->p[i].mtx_meals);
			i++;
		}
		free(sd->mtx_forks);
	}
	if (sd->p)
		free(sd->p);
	pthread_mutex_destroy(&sd->mtx_stop_all);
	pthread_mutex_destroy(&sd->mtx_print);
	pthread_mutex_destroy(&sd->mtx_seat);
	pthread_mutex_destroy(&sd->mtx_tickets);
}

long	now_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000L);
}

void	mtx_print_line(t_philosopher *p, char *line)
{
	long	time;

	if (mtx_stop_get(p->shared_data) == 1)
		return ;
	pthread_mutex_lock(&(p->shared_data->mtx_print));
	if (mtx_stop_get(p->shared_data) == 0)
	{
		time = now_ms() - p->shared_data->start_time;
		printf("%ld %i %s\n", time, p->id, line);
	}
	pthread_mutex_unlock(&(p->shared_data->mtx_print));
}

void	mtx_stop_set(t_shared_data *sd)
{
	pthread_mutex_lock(&(sd->mtx_stop_all));
	sd->stop = 1;
	pthread_mutex_unlock(&(sd->mtx_stop_all));
}

int	mtx_stop_get(t_shared_data *sd)
{
	int	i;

	pthread_mutex_lock(&(sd->mtx_stop_all));
	i = sd->stop;
	pthread_mutex_unlock(&(sd->mtx_stop_all));
	return (i);
}

void	one_philo_case(t_philosopher *p)
{
	pthread_mutex_lock(p->mtx_l_fork);
	mtx_print_line(p, "has taken a fork");
	while (mtx_stop_get(p->shared_data) == 0)
		usleep(1000);
	pthread_mutex_unlock(p->mtx_l_fork);
}

long	mtx_get_ticket(t_shared_data *sd)
{
	long	i;

	pthread_mutex_lock(&sd->mtx_tickets);
	i = sd->next_ticket;
	sd->next_ticket++;
	pthread_mutex_unlock(&sd->mtx_tickets);
	return (i);
}

void	wait_ticket_to_table(t_shared_data *sd, long my_ticket)
{
	while (mtx_stop_get(sd) == 0)
	{
		pthread_mutex_lock(&(sd->mtx_tickets));
		if (sd->now_serving_ticket == my_ticket)
		{
			pthread_mutex_unlock(&(sd->mtx_tickets));
			pthread_mutex_lock(&(sd->mtx_seat));
			if (sd->seats > 0)
			{
				sd->seats--;
				pthread_mutex_unlock(&(sd->mtx_seat));
				pthread_mutex_lock(&(sd->mtx_tickets));
				sd->now_serving_ticket++;
				pthread_mutex_unlock(&(sd->mtx_tickets));
				return ;
			}
			else
				pthread_mutex_unlock(&(sd->mtx_seat));
		}
		else
			pthread_mutex_unlock(&(sd->mtx_tickets));
		usleep(200);
	}
}

void	leave_table(t_shared_data *sd)
{
	pthread_mutex_lock(&(sd->mtx_seat));
	sd->seats++;
	pthread_mutex_unlock(&(sd->mtx_seat));
}

void	sleep_handle(t_philosopher *p, long time)
{
	long	end;

	end = now_ms() + time;
	while (mtx_stop_get(p->shared_data) == 0 && now_ms() < end)
		usleep(200);
	return ;
}

void	sleep_think(t_philosopher *p)
{
	mtx_print_line(p, "is sleeping");
	sleep_handle(p, p->shared_data->time_to_sleep_ms);
	mtx_print_line(p, "is thinking");
}

void	take_fork(t_philosopher *p)
{
	if (p->id % 2 == 0)
	{
		pthread_mutex_lock(p->mtx_l_fork);
		mtx_print_line(p, "has taken a fork");
		pthread_mutex_lock(p->mtx_r_fork);
		mtx_print_line(p, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(p->mtx_r_fork);
		mtx_print_line(p, "has taken a fork");
		pthread_mutex_lock(p->mtx_l_fork);
		mtx_print_line(p, "has taken a fork");
	}
}

void	eat(t_philosopher *p)
{
	mtx_print_line(p, "is eating");
	pthread_mutex_lock(&p->mtx_meals);
	p->last_meal_ms = now_ms();
	p->meals_eaten++;
	pthread_mutex_unlock(&p->mtx_meals);
	sleep_handle(p, p->shared_data->time_to_eat_ms);
}

void	return_fork(t_philosopher *p)
{
	pthread_mutex_unlock(p->mtx_l_fork);
	pthread_mutex_unlock(p->mtx_r_fork);
}

void	*p_routine(void *arg)
{
	t_philosopher	*p;
	long			ticket;

	p = (t_philosopher *)arg;
	if (p->shared_data->n == 1)
		return (one_philo_case(p), NULL);
	if (p->id % 2 == 0)
		usleep(1000);
	while (mtx_stop_get(p->shared_data) == 0)
	{
		ticket = mtx_get_ticket(p->shared_data);
		wait_ticket_to_table(p->shared_data, ticket);
		if (mtx_stop_get(p->shared_data) != 0)
			break ;
		take_fork(p);
		eat(p);
		return_fork(p);
		leave_table(p->shared_data);
		sleep_think(p);
	}
	return (NULL);
}

long	last_mealtime_get(t_philosopher *p)
{
	long	last_mealtime;

	pthread_mutex_lock(&p->mtx_meals);
	last_mealtime = p->last_meal_ms;
	pthread_mutex_unlock(&p->mtx_meals);
	return (last_mealtime);
}

int	meals_get(t_philosopher *p)
{
	int	meals;

	pthread_mutex_lock(&p->mtx_meals);
	meals = p->meals_eaten;
	pthread_mutex_unlock(&p->mtx_meals);
	return (meals);
}

void	handle_death(t_shared_data *sd, int id)
{
	pthread_mutex_lock(&sd->mtx_stop_all);
	if (sd->stop == 1)
	{
		pthread_mutex_unlock(&sd->mtx_stop_all);
		return ;
	}
	sd->stop = 1;
	pthread_mutex_unlock(&sd->mtx_stop_all);
	pthread_mutex_lock(&sd->mtx_print);
	printf("%ld %i died\n", now_ms() - sd->start_time, id);
	pthread_mutex_unlock(&sd->mtx_print);
}

int	someone_died(t_shared_data *sd)
{
	int		i;
	long	deathtime;

	i = 0;
	while (i < sd->n)
	{
		deathtime = last_mealtime_get(&(sd->p[i])) + sd->time_to_die_ms;
		if (now_ms() > deathtime)
		{
			handle_death(sd, sd->p[i].id);
			return (1);
		}
		i++;
	}
	return (0);
}

int	all_eaten(t_shared_data *sd)
{
	int	i;

	i = 0;
	while (i < sd->n)
	{
		if (meals_get(&sd->p[i]) < sd->must_eat)
			return (0);
		i++;
	}
	return (1);
}

void	*m_routine(void *arg)
{
	t_shared_data	*sd;

	sd = (t_shared_data *)arg;
	while (mtx_stop_get(sd) == 0)
	{
		if (someone_died(sd))
			return (NULL);
		if (sd->must_eat > 0 && all_eaten(sd))
			return (mtx_stop_set(sd), NULL);
		usleep(1000);
	}
	return (NULL);
}

int	launch_philos(t_shared_data *sd, int *count)
{
	int	i;

	*count = 0;
	i = 0;
	while (*count < sd->n)
	{
		if (pthread_create(&sd->p[i].thread, NULL, p_routine, &sd->p[i]) != 0)
		{
			mtx_stop_set(sd);
			return (1);
		}
		(*count)++;
		i++;
	}
	return (0);
}

int	launch_monitor(t_shared_data *sd, pthread_t *monitor)
{
	if (mtx_stop_get(sd) == 1)
		return (0);
	if (pthread_create(monitor, NULL, m_routine, sd) != 0)
	{
		mtx_stop_set(sd);
		return (0);
	}
	return (1);
}

void	join_philos(t_shared_data *sd, int created)
{
	while (created--)
		pthread_join(sd->p[created].thread, NULL);
}

int	main(int argc, char **argv)
{
	t_shared_data	sd;
	int				threads_made;
	pthread_t		monitor;

	if (parse_inputs(&sd, argc, argv) != 0)
		return (write(2, "Error: Invalid args", 100), 1);
	sd.start_time = now_ms();
	if (init(&sd) != 0)
		return (write(2, "Error: Init failed\n", 100), 1);
	if (launch_philos(&sd, &threads_made) == 1)
		return (clean_all(&sd), 1);
	if (launch_monitor(&sd, &monitor))
		pthread_join(monitor, NULL);
	mtx_stop_set(&sd);
	join_philos(&sd, threads_made);
	clean_all(&sd);
	return (0);
}
