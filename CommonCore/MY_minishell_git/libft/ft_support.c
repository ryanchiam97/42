/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:31:44 by twtan             #+#    #+#             */
/*   Updated: 2025/06/13 14:31:53 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// 'ft_padding' function 
// Writes to stdout a repetition 'rep' of characters 'padchar'
// increement the count for each character written to stdout.
void	ft_padding(char padchar, int rep, int *count)
{
	int	tmp;

	tmp = -1;
	while (++tmp < rep)
	{
		write (1, &padchar, 1);
		(*count)++;
	}
}

// 'ft_getnum' function 
// Read the character values from 'str', convert and update 'rtn' as type long
// use for translating width and precision
// str - string which width or precision is being parse
// rtn - the parse value
// return a ptr on the str, the end of either width or precision
const char	*ft_getnum(const char *str, long *rtn)
{
	long	num;

	num = 0;
	if ((*str < '0') || (*str > '9'))
		return (str);
	while ((*str >= '0') && (*str <= '9'))
		num = (num * 10) + (*(str++) - '0');
	if (rtn != 0)
		*rtn = num;
	return (str);
}

// 'ft_countnum' function 
// Counts the number of charactors use to represent the number 'ld'
// excludes sign
// default type x or X uses base 16
// if type is diu, use base 10 instead
//
// ld - number to display
// type - type of conversion (hex, HEX, dec, int)
// return number of charactors needed to represent the number
int	ft_countnum(long long ld, char type)
{
	int	count;
	int	base;

	if (ld == 0)
		return (1);
	base = 16;
	count = 0;
	if ((type == 'd') || (type == 'i') || (type == 'u'))
	{
		base = 10;
		if (ld < 0)
		{
			ld *= -1;
			count++;
		}
	}
	else if ((type == 'p') && (ld < 0))
		ld += 0xeffFffffffffffff + 1;
	while (ld != 0)
	{
		ld /= base;
		count++;
	}
	return (count);
}
