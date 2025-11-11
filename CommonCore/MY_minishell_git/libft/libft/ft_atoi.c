/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:23:57 by twtan             #+#    #+#             */
/*   Updated: 2025/05/07 13:08:20 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Converts the initial portion of the string pointed to by nptr to int.
//
// RETURN VALUE
// The converted value or 0 on error.
// if nptr is empty return 0

int	ft_atoi(const char *nptr)
{
	int	value;
	int	flag;

	if (nptr == 0)
		return (0);
	while ((*nptr != 0) && (ft_strchr("\t\n\v\f\r ",*nptr) != 0))
		nptr++;
	flag = 1;
	if ((*nptr != 0) && ((*nptr == '-') || (*nptr == '+')))
	{
		if (*nptr == '-')
			flag = -1;
		nptr++;
	}
	if (*nptr == 0)
		return (0);
	value = 0;
	while ((*nptr >= '0') && (*nptr <= '9'))
	{
		value = (value * 10) + *nptr - '0';
		nptr++;
	}
	return (value * flag);
}

// func: ft_atoi_r
// Convert a string into integer
//
// string must start with '-', '+', or '0' to '9'
// num : return the value of the conversion
//
// Return indicate if the conversion is successful
//        1 successful
//       -1 fail
int	ft_atoi_r(char *str, int *num)
{
	int		idx;
	long	value;

	idx = 0;
	if ((str[idx] == '-') || (str[idx] == '+'))
		idx++;
	if ((str[idx] < '0') || (str[idx] > '9'))
		return (-1);
	value = 0;
	while (str[idx] != 0)
	{
		value = value * 10 + (str[idx] - '0');
		if ((str[idx] < '0') || (str[idx] > '9') \
|| ((value > 2147483647) && (str[0] != '-')) \
|| ((value > 2147483648) && (str[0] == '-')))
			return (-1);
		idx++;
	}
	*num = (int)value;
	if (str[0] == '-')
		*num *= -1;
	return (1);
}
