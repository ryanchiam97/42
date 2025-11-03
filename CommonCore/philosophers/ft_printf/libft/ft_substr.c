/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:14:26 by rchiam            #+#    #+#             */
/*   Updated: 2025/05/28 21:58:05 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output;
	size_t	length_of_string;

	length_of_string = ft_strlen(s);
	if (length_of_string < len)
		len = length_of_string;
	if (start > length_of_string || len < 1)
		return (ft_strdup(""));
	if (start + len > length_of_string)
		len = length_of_string - start;
	output = (char *)malloc(sizeof(char) * len + 1);
	if (output == NULL)
		return (NULL);
	ft_strlcpy(output, s + start, len + 1);
	return (output);
}
// int	main(void)
// {
// 	char *str = ft_strdup("0123456789");
// 	char *s = ft_substr(str, 1000000, 1);
// 	printf("%s", s);
// 	free(s);
// }