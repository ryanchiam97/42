/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:44:47 by rchiam            #+#    #+#             */
/*   Updated: 2025/05/28 19:54:10 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*output;

	i = ft_strlen(s);
	output = 0;
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *) &s[i]);
		i--;
	}
	return (output);
}
