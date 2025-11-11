/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:11:04 by twtan             #+#    #+#             */
/*   Updated: 2025/05/08 22:59:47 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Descriptions
Allocates memory and returns an array of strings obtained by 
splitting ’s’ using the character ’c’ as a delimiter. The array must
end with a NULL pointer.

Additionally, no empty string unless input string is empty or just delimiters

Arguments
s: The string to be split.
c: The delimiter character.

Return
The array of new strings resulting from the split.
NULL if the allocation fails.
*/

// Count the number of word or char separated by delimiter
// s - the string to search in
// c - the delimiter char
//
// separation loop
// 	search word or char loop
//	increement count word
// 	search delimiter(s) loop
static size_t	ft_word_count(char *s, char c)
{
	size_t	w_count;
	size_t	pos;

	if (c == 0)
		return (1);
	w_count = 0;
	pos = 0;
	while (s[pos] != 0)
	{
		while ((s[pos] != c) && (s[pos] != 0))
			pos++;
		w_count++;
		while (s[pos] == c)
			pos++;
	}
	return (w_count);
}

static char	**ft_arry_null(void)
{
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * 1);
	if (arr == 0)
		return (0);
	arr[0] = 0;
	return (arr);
}

static char	**ft_arry_tighten(char **arr)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = arr[0];
	while (arr[i] != 0)
	{
		arr[i] = ft_strdup(arr[i]);
		if (arr[i] == 0)
		{
			while (--i > 0)
				free (arr[i]);
			free (arr[0]);
			free (arr);
			free (tmp);
			return (0);
		}
		i++;
	}
	free (tmp);
	return (arr);
}

static void	ft_setptrs(char c, char *trim, char **arry, size_t w_count)
{
	char	*dspos;
	size_t	i;

	arry[0] = trim;
	i = 0;
	while (i < w_count - 1)
	{
		dspos = ft_strchr(arry[i], c);
		while ((*dspos == c) && (*dspos != 0))
			dspos++;
		arry[i + 1] = dspos;
		*ft_strchr(arry[i++], c) = 0;
	}
	arry[w_count] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**arry;
	char	*trim;
	char	t[2];

	if ((s == 0) || (*s == 0))
		return (ft_arry_null());
	t[0] = c;
	t[1] = 0;
	trim = ft_strtrim(s, t);
	if (trim == 0)
		return (0);
	if (ft_word_count(trim, c) == 0)
	{
		free (trim);
		return (ft_arry_null());
	}
	arry = (char **)malloc(sizeof(char *) * (ft_word_count(trim, c) + 1));
	if (arry == 0)
	{
		free (trim);
		return (0);
	}
	ft_setptrs(c, trim, arry, ft_word_count(trim, c));
	return (ft_arry_tighten(arry));
}
