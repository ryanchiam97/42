/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:22:53 by twtan             #+#    #+#             */
/*   Updated: 2025/05/05 19:46:35 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Descriptions
The function fills the first 'n' bytes of the memory area pointed to by 's' 
with the constant byte 'c'.

Returns
A pointer to the memory area s
*/

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	count;

	if (s == 0)
		return (0);
	count = -1;
	while (++count < n)
		((unsigned char *)s)[count] = (unsigned char)c;
	return (s);
}
