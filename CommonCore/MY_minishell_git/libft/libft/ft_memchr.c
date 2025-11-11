/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:22:53 by twtan             #+#    #+#             */
/*   Updated: 2025/05/06 22:41:30 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// scans  the  initial n bytes of the memory area
// pointed to by s for the first instance of c.  Both c and the  bytes  of
// the memory area pointed to by s are interpreted as unsigned char
//
// return a pointer to the matching byte or NULL if the character does 
// not occur in the given memory area.
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*uc_s;

	if (s == 0)
		return (0);
	uc_s = (unsigned char *)s;
	count = -1;
	while (++count < n)
	{
		if (uc_s[count] == (unsigned char)c)
			return ((void *)(uc_s + count));
	}
	return (0);
}
