/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuychen <yuychen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 21:32:47 by yuychen           #+#    #+#             */
/*   Updated: 2025/12/30 23:12:33 by yuychen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	should_stop(t_data *d)
{
	int	v;

	pthread_mutex_lock(&d->stop_mtx);
	v = d->stop;
	pthread_mutex_unlock(&d->stop_mtx);
	return (v);
}

void	set_stop(t_data *d)
{
	pthread_mutex_lock(&d->stop_mtx);
	d->stop = 1;
	pthread_mutex_unlock(&d->stop_mtx);
}

void	wait_seat(t_data *d)
{
	while (!should_stop(d))
	{
		pthread_mutex_lock(&d->seat_mtx);
		if (d->seats > 0)
		{
			d->seats--;
			pthread_mutex_unlock(&d->seat_mtx);
			return ;
		}
		pthread_mutex_unlock(&d->seat_mtx);
		usleep(200);
	}
}

void	leave_seat(t_data *d)
{
	pthread_mutex_lock(&d->seat_mtx);
	d->seats++;
	pthread_mutex_unlock(&d->seat_mtx);
}

void	print_action(t_philo *p, const char *msg)
{
	long	ts;

	if (should_stop(p->data))
		return ;
	pthread_mutex_lock(&p->data->print_mtx);
	if (!should_stop(p->data))
	{
		ts = now_ms() - p->data->start_ms;
		printf("%ld %d %s\n", ts, p->id, msg);
	}
	pthread_mutex_unlock(&p->data->print_mtx);
}
