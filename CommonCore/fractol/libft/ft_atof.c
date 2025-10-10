/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:56:24 by rchiam            #+#    #+#             */
/*   Updated: 2025/10/10 13:54:57 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	tofloat(const char *str, double *returnfloat, int count, double value)
{
	double	sign;

	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ((*str >= '0' && *str <= '9') || *str == '.')
	{
		if (*str == '.')
		{
			str++;
			continue ;
		}
		value = value * 10 + (*str++ - '0');
	}
	value *= sign;
	while (count--)
		value /= 10.0;
	*returnfloat = (float)value;
}

float	ft_atof(const char *str)
{
	int			i;
	int			count;
	int			decimalptfound;
	double		result;

	i = 0;
	count = 0;
	decimalptfound = 0;
	while (str[i])
	{
		if (decimalptfound == 0 && str[i] == '.')
			decimalptfound = 1;
		else if (decimalptfound == 1 && str[i] == '.')
			return (0);
		else if (decimalptfound == 1 && ft_isdigit(str[i]))
			count++;
		i++;
	}
	result = 0;
	tofloat(str, &result, count, 0);
	return (result);
}
