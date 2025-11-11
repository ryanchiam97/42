/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:35:55 by twtan             #+#    #+#             */
/*   Updated: 2025/05/12 19:55:54 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Descriptions
Copies 'n' bytes from memory area 'src' to memory area 'dest'.
The memory areas must not overlap.

Return
A pointer to dest.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	count;

	if ((dest == 0) || (src == 0) || (n == 0))
		return (dest);
	count = -1;
	while (++count < n)
		((unsigned char *)dest)[count] = ((unsigned char *)src)[count];
	return (dest);
}
