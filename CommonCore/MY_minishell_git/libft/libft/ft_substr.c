/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:19:42 by twtan             #+#    #+#             */
/*   Updated: 2025/05/08 16:35:49 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Descriptions
Allocates memory and returns a substring from the string ’s’.
The substring starts at index ’start’ and has a maximum length of ’len’.

Arguments
s: The original string from which to create the substring.
start: The starting index of the substring within ’s’.
len: The maximum length of the substring.

Returns
The substring.
NULL if the allocation fails.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		slen;
	char		*substr;

	slen = ft_strlen(s);
	if (start > slen)
	{
		substr = (char *)malloc(sizeof(char) * 1);
		if (substr == 0)
			return (0);
		substr[0] = 0;
		return (substr);
	}
	if (slen - start < len)
		len = slen - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == 0)
		return (0);
	ft_strlcpy (substr, s + start, len + 1);
	return (substr);
}
