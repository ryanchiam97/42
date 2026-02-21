/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuychen <yuychen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 21:33:03 by yuychen           #+#    #+#             */
/*   Updated: 2026/01/12 20:43:04 by yuychen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mutexes(t_data *d)
{
	if (pthread_mutex_init(&d->stop_mtx, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&d->print_mtx, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&d->seat_mtx, NULL) != 0)
		return (1);
	return (0);
}

static void	init_philo(t_data *d, int i)
{
	pthread_mutex_init(&d->forks[i], NULL);
	pthread_mutex_init(&d->philos[i].meal_mtx, NULL);
	d->philos[i].last_meal_ms = d->start_ms;
	d->philos[i].meals_eaten = 0;
	d->philos[i].id = i + 1;
	d->philos[i].data = d;
	d->philos[i].left_fork = &d->forks[i];
	d->philos[i].right_fork = &d->forks[(i + 1) % d->n];
}

int	init_all(t_data *d)
{
	int	i;

	d->stop = 0;
	if (init_mutexes(d))
		return (1);
	d->seats = d->n - 1;
	d->forks = malloc(sizeof(pthread_mutex_t) * d->n);
	if (!d->forks)
		return (1);
	d->philos = (t_philo *)malloc(sizeof(t_philo) * d->n);
	if (!d->philos)
		return (1);
	i = 0;
	while (i < d->n)
		init_philo(d, i++);
	return (0);
}
