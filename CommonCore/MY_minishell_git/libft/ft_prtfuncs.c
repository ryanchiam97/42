/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prtfuncs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:37:07 by twtan             #+#    #+#             */
/*   Updated: 2025/06/02 14:37:17 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// 'ft_txt' function
// Display normal text up to null or '%' from 'str' onto stdout
// str - string to display normal text to stdout
// count - increment for each charactor output to stdout
// return the pointer on the 'str' with charactor '%' or null
const char	*ft_txt(const char *str, int *count)
{
	while ((*str != '%') && (*str != 0))
	{
		write (1, str, 1);
		(*count)++;
		str++;
	}
	return (str);
}

char	*ft_prtstr(char *str, size_t len, int *count)
{
	size_t	tmp;

	tmp = 0;
	while ((str[tmp] != 0) && (tmp < len))
	{
		write (1, (str + tmp++), 1);
		(*count)++;
	}
	return (str + tmp);
}

void	ft_prtchr(char c, int *count)
{
	write (1, &c, 1);
	(*count)++;
}

// Display number 'l' to stdout
// return the number of charactors written to stdout
int	ft_showvar_num(long ld)
{
	char	c;
	int		count;

	count = 0;
	if (ld < 0)
	{
		ld *= -1;
		write (1, "-", 1);
		count++;
	}
	if (ld == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	if (ld / 10 != 0)
		count += ft_showvar_num(ld / 10);
	c = (ld % 10) + '0';
	write (1, &c, 1);
	return (count + 1);
}

// Display the number 'ld' as hex to stdout
// ld - number to display in hex
// type - x (lowercase) or X (uppercase output)
// returns the number of charactor written to stdout
int	ft_showvar_hex(size_t ld, char type)
{
	char	*l_hex;
	char	*u_hex;
	int		count;

	if ((type != 'x') && (type != 'X'))
		return (0);
	l_hex = "0123456789abcdef";
	u_hex = "0123456789ABCDEF";
	if (ld == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	count = 0;
	if (ld / 16 > 0)
		count = ft_showvar_hex(ld / 16, type);
	if (type == 'X')
		write (1, u_hex + (ld % 16), 1);
	else
		write (1, l_hex + (ld % 16), 1);
	return (count + 1);
}
