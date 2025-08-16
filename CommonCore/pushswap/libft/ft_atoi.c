/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 23:05:41 by rchiam            #+#    #+#             */
/*   Updated: 2025/05/28 22:29:22 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;

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
	}
	return (i * sign);
}
// may need to handle min and max no. to...
// #include <stdio.h>

// int	main(void)
// {
// 	char	*s;

// 	s = "546:5";
// 	printf("\n%i", ft_atoi(s));
// }
