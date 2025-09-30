/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 03:51:55 by user42            #+#    #+#             */
/*   Updated: 2025/09/30 21:07:05 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	isempty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	weirdending(char *str)
{
	int	i;

	i = ft_strlen(str);
	while (i--)
	{
		if (ft_isdigit(str[i]))
			return (0);
		if (str[i] == '-' || str[i] == '+')
			return (1);
		if (str[i] != ' ' && !ft_isdigit(str[i]))
			return (1);
	}
	return (0);
}

int	checkargvissues(int argc, char **argv)
{
	int			i;
	long long	num;

	i = 0;
	while (i < argc)
	{
		if (isempty(argv[i]))
			return (1);
		if (weirdending(argv[i]))
			return (1);
		num = ft_atoi(argv[i]);
		if (num > (long long) INT_MAX
			|| num < (long long) INT_MIN
		)
			return (1);
		i++;
	}
	return (0);
}

int	checkargvissues2(int argc, char **argv)
{
	int			i;
	long long	num;

	i = 1;
	while (i < argc)
	{
		if (isempty(argv[i]))
			return (1);
		if (weirdending(argv[i]))
			return (1);
		num = ft_atoi(argv[i]);
		if (num > (long long) INT_MAX
			|| num < (long long) INT_MIN
		)
			return (1);
		i++;
	}
	return (0);
}

int	issorted(int *int_arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (int_arr[i] > int_arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

// int isqrt(int n)
// {
//     int x = n;
//     int y = (x + 1) / 2;

//     while (y < x)
//     {
//         x = y;
//         y = (x + n / x) / 2;
//     }
//     return x;
// }
// int imin(int a, int b)
// {
//     if (a < b)
//         return a;
//     return b;
// }
// int imax(int a, int b)
// {
//     if (a > b)
//         return a;
//     return b;
// }
// int ilog2(int n)
// {
//     int log = 0;

//     while (n > 1)
//     {
//         n = n / 2;
//         log++;
//     }
//     return log;
// }
// void    updateminmaxzero(t_stack *s)
// {
//     s->max = 0;
//     s->min = 0;
//     s->maxindex = -1;
//     s->minindex = -1;
// }

// void    updateminmax(t_stack *s)
// {
//     int i;
//     int min;
//     int max;

//     min = INT_MAX;
//     max = INT_MIN;
//     i = 0;
//     if (s->size == 0)
//         return (updateminmaxzero(s));
//     while (i < s->size)
//     {
//         if (s->arr[i] > max)
//         {
//             s->max = s->arr[i];
//             s->maxindex = i;
//         }
//         if (s->arr[i] < min)
//         {
//             s->min = s->arr[i];
//             s->minindex = i;
//         }
//         i++;
//     }
// }
