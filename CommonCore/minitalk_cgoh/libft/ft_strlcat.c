/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 22:10:52 by rchiam            #+#    #+#             */
/*   Updated: 2025/05/10 23:14:58 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	size_t			j;

	i = 0;
	j = 0;
	while (j < size && dest[j])
		j++;
	if (j == size)
		return (size + ft_strlen(src));
	while ((j + i + 1) < size && src[i])
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return (j + ft_strlen(src));
}
// int	main(void)
// {
// 	char dest[] = "Hello, ";
// 	char src[] = "world!";

// 	unsigned int result = ft_strlcat(dest, src, 13);

// 	//  Expected: "Hello, world!"
// 	printf("Resulting string: %s\n", dest);
// 	//  Expected: 13 (length of "Hello, world!")
// 	printf("Total length: %d\n", result);

// 	return (0);
// }