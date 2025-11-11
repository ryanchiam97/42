/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:59:13 by twtan             #+#    #+#             */
/*   Updated: 2025/05/08 16:33:45 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns a pointer to a new string which is a duplicate of the string s
// string s assume to be proper null terminated string
// 
// On success, the strdup() function returns a pointer to the duplicated
// string.  
//
// It returns NULL if insufficient memory was available, 
// with errno set to indicate the cause of the error.

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup_s;

	if (s == 0)
		return (0);
	len = ft_strlen(s);
	dup_s = (char *)malloc (sizeof(char) * (len + 1));
	if (dup_s == 0)
		return (0);
	if (len == 0)
	{
		dup_s[0] = 0;
		return (dup_s);
	}
	ft_strlcpy(dup_s, s, (len + 2));
	return (dup_s);
}
