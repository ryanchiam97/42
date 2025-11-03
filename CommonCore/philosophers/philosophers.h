/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 00:12:26 by rchiam            #+#    #+#             */
/*   Updated: 2025/11/04 00:13:07 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <stdbool.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_config	t_config;

typedef struct philosopher
{
	int				id;
	int				left_fork;
	int				right_fork;
	long			last_meal;
	long			meals_eaten;
	struct s_config	*config;
}	t_philosopher;

struct s_config
{
	int				num_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			start_time;
	int				must_eat;
	pthread_mutex_t	*forks;
}	t_config;

#endif

