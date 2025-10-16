/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:19:28 by rchiam            #+#    #+#             */
/*   Updated: 2025/05/12 14:02:38 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*checks(int n)
{
	char	*s;

	if (n == -2147483648)
	{
		s = malloc(12 * sizeof(char));
		ft_strlcpy(s, "-2147483648", 12);
		return (s);
	}
	if (n == 0)
	{
		s = malloc(2 * sizeof(char));
		ft_strlcpy(s, "0", 2);
		return (s);
	}
	return (malloc(0));
}

char	*int_to_string(char *s, int sign, int digits, int n)
{
	int	i;

	s[sign + digits] = '\0';
	i = 1;
	while (i < sign + digits + 1)
	{
		s[sign + digits - i] = (n % 10) + '0';
		i++;
		n /= 10;
	}
	if (sign == 1)
		s[0] = '-';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		sign;
	int		digits;
	int		i;

	if (n == 0 || n == -2147483648)
		return (checks(n));
	sign = 0;
	if (n < 0)
	{
		n = -n;
		sign = 1;
	}
	i = n;
	digits = 0;
	while (i > 0)
	{
		i /= 10;
		digits++;
	}
	s = malloc(sign + digits + 1);
	if (s == NULL)
		return (NULL);
	return (int_to_string(s, sign, digits, n));
}
// #include <limits.h>
// int	main(void)
// {
// 	printf("\n%s\n", ft_itoa(INT_MIN));
// 	return (0);
// }