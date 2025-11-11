/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:29:25 by rchiam            #+#    #+#             */
/*   Updated: 2025/05/10 19:46:31 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*output;

	output = malloc(sizeof(t_list) * 1);
	if (output == NULL)
		return (NULL);
	output->content = content;
	output->next = NULL;
	return (output);
}

// int	main(void)
// {
// 	char s[] = "I AM TESTING THIS !!! \n";
// 	t_list *testernodeptr = ft_lstnew(s);
// 	printf("%s", (char *)testernodeptr->content);
// }