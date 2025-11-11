/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:06:32 by twtan             #+#    #+#             */
/*   Updated: 2025/05/06 23:31:24 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	locates the first occurrence of the null-terminated string little 
//	in the string big, where not more than len characters are searched.
//
//	Return :
//      If little is an empty string, big is returned; 
//      if little occurs nowhere in big, NULL is returned; 
//      otherwise a pointer to the first character of the first occurrence 
//      of little is returned.
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	count;
	size_t	l_len;
	int		i;

	if (*little == 0)
		return ((char *)big);
	l_len = ft_strlen(little);
	if (len < l_len)
		return (0);
	count = -1;
	while ((*big != 0) && (++count <= len - l_len))
	{
		i = 0;
		while ((little[i] != 0) && (little[i] == big[i]))
		{
			if (little[i + 1] == 0)
				return ((char *)big);
			if (big[i + 1] == 0)
				return (0);
			i++;
		}
		big++;
	}
	return (0);
}
