/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 22:19:05 by twtan             #+#    #+#             */
/*   Updated: 2025/05/09 22:58:20 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Description
Applies the function f to each character of the string s, 
passing its index as the first argument and the character
itself as the second. A new string is created to store the
results from the successive applications of f.

Arguments
s: The string to iterate over.
f: The function to apply to each character.

Returns
The string created from the successive applications of ’f’.
Returns NULL if the allocation fails.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mem;
	size_t	len;
	size_t	tmp;

	if ((s == 0) || (f == 0))
		return (0);
	len = ft_strlen(s);
	mem = (char *)malloc(sizeof(char) * (len + 1));
	if (mem == 0)
		return (0);
	tmp = -1;
	while (++tmp < len)
		mem[tmp] = f(tmp, s[tmp]);
	mem[len] = 0;
	return (mem);
}
