/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuychen <yuychen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 21:32:56 by yuychen           #+#    #+#             */
/*   Updated: 2025/12/30 23:13:33 by yuychen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->data->n == 1)
		return (one_philo_case(p));
	if (p->id % 2 == 0)
		usleep(1000);
	while (!should_stop(p->data))
	{
		wait_seat(p->data);
		take_forks(p);
		eat(p);
		put_forks(p);
		leave_seat(p->data);
		sleep_and_think(p);
	}
	return (NULL);
}

/*
print_action(p, "is thinking");
usleep(1000 * 100);
*/