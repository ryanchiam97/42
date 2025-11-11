/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:06:32 by twtan             #+#    #+#             */
/*   Updated: 2025/05/12 20:14:59 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Descriptions
Compares the two strings s1 and s2.
The comparison is done using unsigned characters.

Return
returns an integer indicating the result of the comparison, as follows:
       • 0, if the s1 and s2 are equal;
       • a negative value if s1 is less than s2;
       • a positive value if s1 is greater than s2.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			count;
	unsigned char	*uc_s1;
	unsigned char	*uc_s2;

	if ((n == 0) || (s1 == 0) || (s2 == 0))
		return (0);
	uc_s1 = (unsigned char *)s1;
	uc_s2 = (unsigned char *)s2;
	count = 0;
	while ((count < n) && (uc_s1 != 0) && (uc_s2 != 0))
	{
		if (*uc_s1 != *uc_s2)
			return (*uc_s1 - *uc_s2);
		uc_s1++;
		uc_s2++;
		count++;
	}
	return (*uc_s1 - *uc_s2);
}
