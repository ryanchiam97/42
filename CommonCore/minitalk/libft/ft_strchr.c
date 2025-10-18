/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:22:24 by rchiam            #+#    #+#             */
/*   Updated: 2025/05/28 19:55:14 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*output;

	i = 0;
	output = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (output);
}
// int	main(void)
// {
// 	char s[] = "tripouille";
// 	char *p = ft_strchr(s, 't'+256);
// 	printf("%s", p);
// }