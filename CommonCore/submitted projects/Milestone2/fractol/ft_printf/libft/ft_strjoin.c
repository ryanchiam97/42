/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:15:30 by rchiam            #+#    #+#             */
/*   Updated: 2025/05/27 20:07:23 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*output;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	output = malloc (len * sizeof(char));
	if (output == NULL)
		return (NULL);
	ft_strlcpy(output, s1, len);
	ft_strlcat(output, s2, len);
	return (output);
}

// int	main(void)
// {
// 	char const *s1 = "\0";
// 	char const *s2 = "hi";
// 	printf("\n%s\n", ft_strjoin(s1, s2));
// }