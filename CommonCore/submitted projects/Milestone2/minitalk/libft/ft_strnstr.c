/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:43:36 by rchiam            #+#    #+#             */
/*   Updated: 2025/05/28 20:34:16 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*little == '\0')
		return (((char *)big));
	if (n == 0)
		return (0);
	while (*big != 0 && (j < n))
	{
		i = 0;
		while (big[i] && little[i] && big[i] == little[i] && j + i < n)
			i++;
		if (little[i] == '\0')
			return ((char *)big);
		big++;
		j++;
	}
	return (0);
}
// int	main(void)
// {
// 	const char haystack[30] = "aaabcabcd";
// 	const char needle[10] = "aabc";
// 	printf("%s\n", ft_strnstr(haystack, "aaabc", 5));
// }