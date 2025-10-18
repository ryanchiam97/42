/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:42:58 by rchiam            #+#    #+#             */
/*   Updated: 2025/05/10 19:45:56 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (s < d && s + n > d)
	{
		while (i < n)
		{
			*(d + n - 1 - i) = *(s + n - 1 - i);
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			*(d + i) = *(s + i);
			i++;
		}
	}
	return (dest);
}

/*
no overlap
src							[][][][][][]
dst			[][][][][][]
(front to back)
src			[][][][][][]
dst							[][][][][][]
(front to back)

overlap but src behind
src				[][][][][][]
dst			[][][][][][]
(front to back)

overlap and src ahead (cause overwrite)
src				[][][][][][]
dst					[][][][][][]
(back to front)
*/