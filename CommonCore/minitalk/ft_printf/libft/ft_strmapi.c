/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:20:10 by rchiam            #+#    #+#             */
/*   Updated: 2025/05/10 19:44:17 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*output;
	int		i;

	if (!s || !f)
		return (NULL);
	output = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (output == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		output[i] = f(i, s[i]);
		i++;
	}
	output[i] = '\0';
	return (output);
}
// #include <stdio.h>

// char	test(unsigned int i, char c)
// {
// 	return ('A');
// }

// int	main(void)
// {
// 	printf("%s", ft_strmapi("hello", test));
// 	return (0);
// }
