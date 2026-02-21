/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuychen <yuychen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 18:37:26 by yuychen           #+#    #+#             */
/*   Updated: 2026/01/12 21:20:59 by yuychen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philo_case(t_philo *p)
{
	pthread_mutex_lock(p->left_fork);
	print_action(p, "has taken a fork");
	while (!should_stop(p->data))
		usleep(1000);
	pthread_mutex_unlock(p->left_fork);
	return (NULL);
}

void	take_forks(t_philo *p)
{
	if (p->id % 2 == 0)
	{
		pthread_mutex_lock(p->right_fork);
		print_action(p, "has taken a fork");
		pthread_mutex_lock(p->left_fork);
		print_action(p, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(p->left_fork);
		print_action(p, "has taken a fork");
		pthread_mutex_lock(p->right_fork);
		print_action(p, "has taken a fork");
	}
}

void	eat(t_philo *p)
{
	print_action(p, "is eating");
	pthread_mutex_lock(&p->meal_mtx);
	p->last_meal_ms = now_ms();
	p->meals_eaten++;
	pthread_mutex_unlock(&p->meal_mtx);
	smart_sleep(p->data->t_eat, p->data);
}

void	put_forks(t_philo *p)
{
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
}

void	sleep_and_think(t_philo *p)
{
	print_action(p, "is sleeping");
	smart_sleep(p->data->t_sleep, p->data);
	print_action(p, "is thinking");
}
