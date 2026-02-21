/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuychen <yuychen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 18:03:35 by yuychen           #+#    #+#             */
/*   Updated: 2025/12/30 23:10:04 by yuychen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_all(t_data *d)
{
	int	i;

	if (d->forks)
	{
		i = 0;
		while (i < d->n)
		{
			pthread_mutex_destroy(&d->forks[i]);
			pthread_mutex_destroy(&d->philos[i].meal_mtx);
			i++;
		}
		free(d->forks);
	}
	if (d->philos)
		free(d->philos);
	pthread_mutex_destroy(&d->stop_mtx);
	pthread_mutex_destroy(&d->print_mtx);
	pthread_mutex_destroy(&d->seat_mtx);
}
