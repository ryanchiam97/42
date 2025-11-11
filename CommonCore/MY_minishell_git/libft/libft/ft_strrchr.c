/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:23:57 by twtan             #+#    #+#             */
/*   Updated: 2025/05/12 20:14:02 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// return the pointer to the last occurence of character c in the string s
// if c is /0 then return pointer of the /0 in the string s
// return null if the character is not found
char	*ft_strrchr(const char *s, int c)
{
	char	*tmp_s;
	char	cc;

	cc = (char) c;
	tmp_s = 0;
	while (*s != 0)
	{
		if (*s == cc)
			tmp_s = (char *)s;
		s++;
	}
	if (*s == cc)
		return ((char *)s);
	return (tmp_s);
}
