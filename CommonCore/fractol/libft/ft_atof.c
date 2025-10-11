/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:56:24 by rchiam            #+#    #+#             */
/*   Updated: 2025/10/11 15:28:59 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	do_atof(const char *str, double *returnval)
{
	double	sign;
	int		decimalfound;
	int		count;
	double	value;
	int		i;

	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	count = 1;
	i = 0;
	decimalfound = 0;
	value = 0;
	while (str[i])
	{
		if (str[i] == '.' && decimalfound == 0)
		{
			i++;
			decimalfound = 1;
			continue ;
		}
		else if ((str[i] == '.' && decimalfound == 1))
			return (0);
		else if (str[i] >= '0' && str[i] <= '9')
		{
			value = value * 10 + (str[i] - '0');
			if (decimalfound == 1)
				count *= 10;
		}
		else if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	*returnval = (value * sign / count);
	return (1);
}

float	ft_atof(const char *str)
{
	double	returnfloat;

	if (do_atof(str, &returnfloat))
		return ((float)returnfloat);
	return (0.0f);
}

// float	ft_atof(const char *str)
// {
// 	int			i;
// 	int			count;
// 	int			decimalptfound;
// 	double		result;

// 	i = 0;
// 	count = 1;
// 	decimalptfound = 0;
// 	while (str[i])
// 	{
// 		if (decimalptfound == 0 && str[i] == '.')
// 			decimalptfound = 1;
// 		else if (decimalptfound == 1 && str[i] == '.')
// 			return (0);
// 		else if (decimalptfound == 1 && ft_isdigit(str[i]))
// 			count *= 10;
// 		i++;
// 	}
// 	result = 0;
// 	tofloat(str, &result, 0);
// 	return (result / count);
// }// To Fix
