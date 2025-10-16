/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:17:28 by rchiam            #+#    #+#             */
/*   Updated: 2025/05/10 19:46:08 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*s1p;
	unsigned char	*s2p;

	i = 0;
	if (n == 0)
		return (0);
	s1p = (unsigned char *)s1;
	s2p = (unsigned char *)s2;
	while (i < n)
	{
		if (*(s1p + i) != *(s2p + i))
			return (*(s1p + i) - *(s2p + i));
		i++;
	}
	return (0);
}
