/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:22:53 by twtan             #+#    #+#             */
/*   Updated: 2025/05/07 13:09:41 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Description
Compares the first n bytes (each interpreted as unsigned char) 
of the memory areas s1 and s2.

Returns
Return an integer less than, equal to, or greater than zero 
if the first n bytes of s1 is found, 
respectively, to be less than, to match, or be greater than the first n
bytes of s2.

For a nonzero return value, the sign is determined by the sign of the 
difference between the first  pair  of  bytes
(interpreted as unsigned char) that differ in s1 and s2.

If n is zero, the return value is zero.

*/

// compares the first n bytes (each interpreted as unsigned char) 
// of the memory areas s1 and s2.
//
// return 0 if s1 == s2
// return -ve if s1 < s2
// return +ve if s1 > s2
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			count;
	unsigned char	*uc_s1;
	unsigned char	*uc_s2;

	if ((n == 0) || (s1 == 0) || (s2 == 0))
		return (0);
	uc_s1 = (unsigned char *)s1;
	uc_s2 = (unsigned char *)s2;
	count = -1;
	while (++count < n)
	{
		if (*uc_s1 != *uc_s2)
			return (*uc_s1 - *uc_s2);
		uc_s1++;
		uc_s2++;
	}
	return (0);
}
