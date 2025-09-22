/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 23:05:41 by rchiam            #+#    #+#             */
/*   Updated: 2025/09/22 21:14:45 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str)
{
	long long	i;
	long long	sign;

	i = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		i *= 10;
		i += *str - '0';
		str++;
		if (i > 2147483647 && sign == 1)
			return (2147483648);
		else if (i > 2147483648 && sign == -1)
			return (-2147483649);
	}
	return (i * sign);
}
