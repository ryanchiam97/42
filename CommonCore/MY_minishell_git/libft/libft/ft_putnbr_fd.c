/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 23:20:58 by twtan             #+#    #+#             */
/*   Updated: 2025/05/09 23:43:26 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Descriptions
Outputs the integer ’n’ to the specified file descriptor.

Arguments
n: The integer to output.
fd: The file descriptor on which to write.
*/

void	ft_putnbr_fd(int n, int fd)
{
	long	l_n;
	char	digits[11];
	int		pos;

	if (fd < 0)
		return ;
	if (n == 0)
	{
		write (fd, "0", 1);
		return ;
	}
	l_n = n;
	if (l_n < 0)
	{
		l_n *= -1;
		write (fd, "-", 1);
	}
	pos = 0;
	while (l_n > 0)
	{
		digits[pos++] = l_n % 10 + '0';
		l_n /= 10;
	}
	while (--pos >= 0)
		write (fd, &digits[pos], 1);
}
