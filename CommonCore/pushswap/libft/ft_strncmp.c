/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 19:29:52 by rchiam            #+#    #+#             */
/*   Updated: 2025/05/26 21:22:16 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (((unsigned char)s1[i] && (unsigned char)s2[i]) && (i < n))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
// #include <stdio.h>
//  int main()
//  {
// 	char *s1 = "hillo";
// 	char *s2 = "helloThere";
// 	unsigned int i = 0;
// 	printf("%i",ft_strncmp(s1, s2, i));
// 	return (0);
//  }