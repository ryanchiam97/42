/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:02:25 by twtan             #+#    #+#             */
/*   Updated: 2025/05/10 19:25:33 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size - max size of dst array
//        copy until size - 1 (reserve ft_substrfor null terminator)
//
// src - pointer to source string
// dst - pointer to destination string
//
// return value should be same as src length if there is enough dst space
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	slen;

	slen = ft_strlen(src);
	if (size == 0)
		return (slen);
	count = -1;
	while ((*src != 0) && (++count < size - 1))
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = 0;
	return (slen);
}
