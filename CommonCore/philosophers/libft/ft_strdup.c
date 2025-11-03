/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:25:04 by rchiam            #+#    #+#             */
/*   Updated: 2025/08/23 22:24:52 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	int		len;

	if (src == NULL)
		return (NULL);
	len = ft_strlen(src) + 1;
	dest = (char *)malloc(sizeof(char) * len);
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, src, len);
	return (dest);
}
