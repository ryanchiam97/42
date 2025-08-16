/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:16:11 by rchiam            #+#    #+#             */
/*   Updated: 2025/05/28 22:33:21 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*trimmer(char *output, char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*output;

	output = NULL;
	return (trimmer(output, s1, set));
}

int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

char	*trimmer(char *output, char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && is_in_set(s1[i], set))
		i++;
	while (j >= i && is_in_set(s1[j], set))
		j--;
	output = ft_substr(s1, (unsigned int)i, (size_t)j - i + 1);
	return (output);
}

// int	main(void)
// {
// 	char const s1[] = "XXabcXX";
// 	char const s2[] = "X";
// 	char *t = ft_strtrim(s1, s2);
// 	printf("%s", t);
// 	free(t);
// }