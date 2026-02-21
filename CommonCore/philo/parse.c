/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuychen <yuychen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 18:05:16 by yuychen           #+#    #+#             */
/*   Updated: 2025/12/30 18:31:25 by yuychen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_num(const char *s)
{
	int	i;

	i = 0;
	if (!s || !s[0])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static long	atolong(const char *s)
{
	long	n;
	int		i;

	n = 0;
	i = 0;
	while (s[i])
	{
		n = n * 10 + (s[i] - '0');
		i++;
	}
	return (n);
}

int	parse_args(t_data *d, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (1);
	if ((!is_num(av[1]) || !is_num(av[2]) || !is_num(av[3]) || !is_num(av[4]))
		|| (ac == 6 && !is_num(av[5])))
		return (1);
	d->n = (int)atolong(av[1]);
	d->t_die = atolong(av[2]);
	d->t_eat = atolong(av[3]);
	d->t_sleep = atolong(av[4]);
	d->must_eat = -1;
	if (ac == 6)
		d->must_eat = (int)atolong(av[5]);
	if (d->n <= 0 || d->t_eat <= 0 || d->t_die <= 0 || d->t_sleep <= 0)
		return (1);
	return (0);
}
