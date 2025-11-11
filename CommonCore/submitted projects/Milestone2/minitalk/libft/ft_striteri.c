/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:20:51 by rchiam            #+#    #+#             */
/*   Updated: 2025/05/10 19:44:51 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}

// void	makeA(unsigned int i, char *address)
// {
// 	*address = 'A';
// }
// #include <stdio.h>

// int	main(void)
// {
// 	char s[] = "hello";

// 	ft_striteri(s, makeA);
// 	printf("%s", s);
// 	return (0);
// }