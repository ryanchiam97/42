/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:17:30 by twtan             #+#    #+#             */
/*   Updated: 2025/05/09 22:18:26 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Descriptions
Allocates memory and returns a string representing the integer received as an
argument. Negative numbers must be handled.

Arguments
n: The integer to convert

Returns
The string representing the integer.
NULL if the allocation fails.

Code flow
int max need 12 char to store -2 147 483 647 (null)
1. Convert -ve to +ve and long to process
2. Determine the number of digits and store each digit in buffer
3. Allocate memory 1 sign + number of digit + 1 null
4. Write buffer into allocated memory
5. terminate 
*/

static int	ndigits(long l_n)
{
	int	pos;

	pos = 0;
	if (l_n == 0)
		pos = 1;
	while (l_n > 0)
	{
		l_n /= 10;
		pos++;
	}
	return (pos);
}

char	*ft_itoa(int n)
{
	int		pos;
	char	*str;
	long	l_n;

	l_n = n;
	pos = 0;
	if (l_n < 0)
	{
		l_n *= -1;
		pos++;
	}
	pos += ndigits(l_n);
	str = (char *)malloc(sizeof(char) * (pos + 1));
	if (str == 0)
		return (0);
	str[pos] = 0;
	while (--pos >= 0)
	{
		*(str + pos) = (l_n % 10) + '0';
		l_n /= 10;
	}
	if (n < 0)
		*str = '-';
	return (str);
}
