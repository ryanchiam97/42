/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuychen <yuychen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 21:15:37 by yuychen           #+#    #+#             */
/*   Updated: 2026/01/10 17:31:06 by yuychen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	get_meals(t_philo *p)
{
	int	v;

	pthread_mutex_lock(&p->meal_mtx);
	v = p->meals_eaten;
	pthread_mutex_unlock(&p->meal_mtx);
	return (v);
}

static int	everyone_ate_enough(t_data *d)
{
	int	i;

	if (d->must_eat <= 0)
		return (0);
	i = 0;
	while (i < d->n)
	{
		if (get_meals(&d->philos[i]) < d->must_eat)
			return (0);
		i++;
	}
	return (1);
}

long	get_last_meal_ms(t_philo *p)
{
	long	v;

	pthread_mutex_lock(&p->meal_mtx);
	v = p->last_meal_ms;
	pthread_mutex_unlock(&p->meal_mtx);
	return (v);
}

void	die_and_stop(t_data *d, int id)
{
	long	ts;

	pthread_mutex_lock(&d->stop_mtx);
	if (d->stop)
	{
		pthread_mutex_unlock(&d->stop_mtx);
		return ;
	}
	d->stop = 1;
	pthread_mutex_unlock(&d->stop_mtx);
	pthread_mutex_lock(&d->print_mtx);
	ts = now_ms() - d->start_ms;
	printf("%ld %d died\n", ts, id);
	pthread_mutex_unlock(&d->print_mtx);
}

void	*monitor_routine(void *arg)
{
	t_data	*d;
	int		i;
	long	last;
	long	now;

	d = (t_data *)arg;
	while (!should_stop(d))
	{
		i = 0;
		while (i < d->n && !should_stop(d))
		{
			last = get_last_meal_ms(&d->philos[i]);
			now = now_ms();
			if (now - last > d->t_die)
			{
				die_and_stop(d, d->philos[i].id);
				return (NULL);
			}
			i++;
		}
		if (everyone_ate_enough(d))
			return (set_stop(d), NULL);
		usleep(1000);
	}
	return (NULL);
}
