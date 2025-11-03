/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uprintnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:40:02 by rchiam            #+#    #+#             */
/*   Updated: 2025/06/14 15:29:40 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	uprintnbr(unsigned int n, int i_unsigned, int count)
{
	char	c;

	if (i_unsigned == 0)
		return (write(1, "0", 1), 1);
	else
		n = (unsigned int)n;
	if (n >= 10)
		count = uprintnbr((n / 10), i_unsigned, count);
	c = (n % 10) + '0';
	write(1, &c, 1);
	count += 1;
	return (count);
}
