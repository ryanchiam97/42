/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:40:14 by rchiam            #+#    #+#             */
/*   Updated: 2025/06/14 17:54:47 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printhex(unsigned int p, int caps, int count)
{
	char	*ref;
	char	c;

	if (caps == -1)
	{
		write(1, "0x", 2);
		caps = 10;
	}
	if (caps == 1)
		ref = "0123456789ABCDEF";
	else
		ref = "0123456789abcdef";
	if (p >= 16)
		count = printhex(p / 16, caps, count);
	c = ref[p % 16];
	write(1, &c, 1);
	count += 1;
	return (count);
}
