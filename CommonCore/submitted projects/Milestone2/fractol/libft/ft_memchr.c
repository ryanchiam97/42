/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:12:30 by rchiam            #+#    #+#             */
/*   Updated: 2025/05/12 15:38:23 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*output;
	size_t			i;

	i = 0;
	output = (unsigned char *)s;
	while (i < n)
	{
		if (*output == (unsigned char)c)
			return (output);
		output++;
		i++;
	}
	return (NULL);
}
// int main()
// {
// 	char s[13] = "Hello world!";
// 	printf("%c", *((char *)ft_memchr(s, 'W', 13)));
// }