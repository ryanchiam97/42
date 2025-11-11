/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:23:57 by twtan             #+#    #+#             */
/*   Updated: 2025/05/12 20:11:35 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// return the pointer to the first occurence of character c in the string s
// if c is /0 then return pointer of the /0 in the string s
// return null if the character is not found
//
char	*ft_strchr(const char *s, int c)
{
	char	cc;

	cc = (char)c;
	while ((*s != cc) && (*s != 0))
		s++;
	if (*s != cc)
		return (0);
	return ((char *)s);
}
