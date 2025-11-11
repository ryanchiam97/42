/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:02:25 by twtan             #+#    #+#             */
/*   Updated: 2025/05/09 23:44:29 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function append src string to end of dst string
// append length = size - strlen(dst) - 1 byte (for dst terminating null)
//
// size - max size of dst
// src - pointer to source string
// dst - pointer to destination string
//
// return the value of dst string + length of src string

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (size <= dst_len)
		return (size + src_len);
	dst += dst_len;
	count = 0;
	while ((*src != 0) && (count + dst_len < size - 1))
	{
		*dst = *src;
		dst++;
		src++;
		count++;
	}
	*dst = 0;
	return (dst_len + src_len);
}
