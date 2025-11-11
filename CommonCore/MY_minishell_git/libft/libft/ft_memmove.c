/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:35:55 by twtan             #+#    #+#             */
/*   Updated: 2025/05/12 19:59:06 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// memory are allocated contiguous (sequential uninterrupted blocks)
//
// normal memory without overlap
// (src              )      (              dst)
//
// memory overlap may occur in 2 forms
// (src     ( overlap area )    dst)
// (dst     ( overlap area )    src)
//
// memory area from src may risk overwritten before reading in the overlap area
// (src     ( overlap area )    dst)
//
// src   123456789
//	       789000000  dst
//
// after moving without checking
// src   123456123
//             123456123  dst
//
// Copies n bytes from memory area src to memory area dest
// returns a pointer to dest
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	count;
	void	*tmp_dest;

	if (src == dest)
		return (dest);
	tmp_dest = dest;
	if (src < dest)
	{
		while (n > 0)
		{
			*((unsigned char *)dest + n - 1) = *((unsigned char *)src + n - 1);
			n--;
		}
		return (tmp_dest);
	}
	count = -1;
	while (++count < n)
	{
		*((unsigned char *)dest) = *((unsigned char *)src);
		src++;
		dest++;
	}
	return (tmp_dest);
}
