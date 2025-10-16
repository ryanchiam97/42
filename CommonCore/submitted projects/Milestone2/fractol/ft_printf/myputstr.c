/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myputstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:41:07 by rchiam            #+#    #+#             */
/*   Updated: 2025/06/14 15:21:48 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	myftputstr(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (write(1, "(null)", 6), 6);
	while (s[i])
	{
		write(1, &(s[i]), 1);
		count++;
		i++;
	}
	return (count);
}
