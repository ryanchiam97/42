/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:40:11 by rchiam            #+#    #+#             */
/*   Updated: 2025/06/14 15:21:59 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printnbr(int n, int i_unsigned, int count)
{
	char	c;

	if (i_unsigned == 0)
	{
		if (n == -2147483648)
			return (write(1, "-2147483648", 11), 11);
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
			count++;
		}
	}
	else
		n = (unsigned int)n;
	if (n >= 10)
		count = printnbr((n / 10), i_unsigned, count);
	c = (n % 10) + '0';
	write(1, &c, 1);
	count += 1;
	return (count);
}
