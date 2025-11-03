/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:56:24 by rchiam            #+#    #+#             */
/*   Updated: 2025/10/12 15:02:34 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	loop(double *returnvalue, const char *str, int *count, int decimalfound)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (decimalfound == 1)
				return (0);
			decimalfound = 1;
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			*returnvalue = *returnvalue * 10 + (str[i] - '0');
			if (decimalfound == 1)
				*count *= 10;
		}
		else
			return (0);
		i++;
	}
	return (1);
}

int	do_atof(const char *str, double *returnval)
{
	double	sign;
	int		count;

	sign = 1;
	*returnval = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	count = 1;
	if (!loop(returnval, str, &count, 0))
		return (0);
	*returnval = (*returnval * sign / count);
	return (1);
}

float	ft_atof(const char *str, int *resultvalidity)
{
	double	returnfloat;

	*resultvalidity = 0;
	if (do_atof(str, &returnfloat))
	{
		*resultvalidity = 1;
		return ((float)returnfloat);
	}
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
