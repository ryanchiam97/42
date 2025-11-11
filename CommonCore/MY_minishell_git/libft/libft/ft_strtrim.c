/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:06:06 by twtan             #+#    #+#             */
/*   Updated: 2025/05/12 14:55:07 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Descriptions
Allocates memory and returns a copy of ’s1’ with characters from ’set’ removed
from the beginning and the end.

Arguments
s1: The string to be trimmed.
set: The string containing the set of characters to be removed.

Returns
The trimmed string.
NULL if the allocation fails.
*/

/*
 * program flow
 * 1. Search start of 's1' for consecutive char in 'set' and increement 's1' ptr
 * 2. Find the 'len' of 's1'(trimmed start)
 * 3. Search end of 's1' for consecutive char in 'set' and decreement 'len'.
 * 4. note len starts 1, index starts 0
 * 5. Allocate memory using 'len'
 * 6. String copy 's1'(trimmed start) to 'trim' for 'len' bytes.
 * 7. return 'trim'
 */

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	len;

	while ((ft_strchr(set, *s1) != 0) && (*s1 != 0))
		s1++;
	len = ft_strlen(s1);
	if (len == 0)
	{
		trim = (char *)malloc(sizeof(char) * 1);
		if (trim == 0)
			return (0);
		*trim = 0;
		return (trim);
	}
	while (ft_strchr(set, s1[len]) != 0)
		len--;
	len ++;
	trim = (char *)malloc(sizeof(char) * (len + 1));
	if (trim == 0)
		return (0);
	ft_strlcpy(trim, s1, len + 1);
	return (trim);
}

/*
#include <stdio.h>

int	main()
{
	char	*str1;
	char	*set;
	char	*tmp;

	str1 = "\\ *** Much*Ado/About\\ Nothing *** ///";
	set = "\\/ *";
	tmp = ft_strtrim(str1, set);
	printf("%s",tmp);
	free (tmp);
}*/
