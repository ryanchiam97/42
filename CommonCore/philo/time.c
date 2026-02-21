/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuychen <yuychen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 21:32:50 by yuychen           #+#    #+#             */
/*   Updated: 2026/01/12 21:28:36 by yuychen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	now_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000L);
}

void	smart_sleep(long ms, t_data *d)
{
	long	end;

	end = now_ms() + ms;
	while (!should_stop(d) && now_ms() < end)
		usleep(200);
}
