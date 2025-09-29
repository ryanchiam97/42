/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:52:28 by rchiam            #+#    #+#             */
/*   Updated: 2025/05/28 21:06:42 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*output;

	if (nmemb == 0 || size <= 0)
		return (malloc(0));
	if (nmemb * size / size != nmemb)
		return (NULL);
	output = malloc(nmemb * size);
	if (output == NULL)
		return (NULL);
	ft_memset((void *)output, '\0', nmemb * size);
	return ((void *)output);
}
// int	main(void)
// {
// 	void *p = ft_calloc(18446744073709551615UL, 18446744073709551615UL);
// 	free(p);
// 	return (0);
// }