/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuychen <yuychen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 21:33:01 by yuychen           #+#    #+#             */
/*   Updated: 2026/01/01 21:48:45 by yuychen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	launch_philos(t_data *d, int *created)
{
	*created = 0;
	while (*created < d->n)
	{
		if (pthread_create(&d->philos[*created].thread, NULL, philo_routine,
				&d->philos[*created]) != 0)
		{
			set_stop(d);
			write(2, "Error: thread create\n", 21);
			return (1);
		}
		(*created)++;
	}
	return (0);
}

static int	launch_monitor(t_data *d, pthread_t *monitor)
{
	if (should_stop(d))
		return (0);
	if (pthread_create(monitor, NULL, monitor_routine, d) != 0)
	{
		set_stop(d);
		write(2, "Error: monitor create\n", 22);
		return (0);
	}
	return (1);
}

static void	join_philos(t_data *d, int created)
{
	int	i;

	i = 0;
	while (i < created)
	{
		pthread_join(d->philos[i].thread, NULL);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data		d;
	int			created;
	int			monitor_created;
	pthread_t	monitor;

	if (parse_args(&d, ac, av))
		return (write(2, "Error: invalid args\n", 20), 1);
	d.start_ms = now_ms();
	if (init_all(&d))
		return (write(2, "Error: init failed\n", 19), 1);
	if (launch_philos(&d, &created))
		return (clean_all(&d), 1);
	monitor_created = launch_monitor(&d, &monitor);
	if (monitor_created)
		pthread_join(monitor, NULL);
	set_stop(&d);
	join_philos(&d, created);
	clean_all(&d);
	return (0);
}

/*
int	main(int ac, char **av)
{
	t_data		d;
	int			i;
	int			created;
	int			monitor_created;
	pthread_t	monitor;

	if (parse_args(&d, ac, av))
		return (write(2, "Error: invalid args\n", 20), 1);
	d.start_ms = now_ms();
	if (init_all(&d))
		return (write(2, "Error: init failed\n", 19), 1);
	created = 0;
	while (created < d.n)
	{
		if (pthread_create(&d.philos[created].thread, NULL, philo_routine,
				&d.philos[created]) != 0)
		{
			set_stop(&d);
			write(2, "Error: thread create\n", 21);
			break ;
		}
		created++;
	}
	monitor_created = 0;
	if (!should_stop(&d))
	{
		if (pthread_create(&monitor, NULL, monitor_routine, &d) == 0)
			monitor_created = 1;
		else
			set_stop(&d);
	}
	if (monitor_created)
		pthread_join(monitor, NULL);
	set_stop(&d);
	i = 0;
	while (i < created)
	{
		pthread_join(d.philos[i].thread, NULL);
		i++;
	}
	clean_all(&d);
	return (0);
}
*/