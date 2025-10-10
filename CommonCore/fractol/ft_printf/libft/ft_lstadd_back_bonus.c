/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:31:15 by rchiam            #+#    #+#             */
/*   Updated: 2025/05/27 22:22:27 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
}
// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*output;

// 	output = malloc(sizeof(t_list) * 1);
// 	if (output == NULL)
// 		return (NULL);
// 	output->content = content;
// 	output->next = NULL;
// 	return (output);
// }
// int	main(void)
// {
// 	char s1[] = "one";
// 	char s2[] = "two";
// 	t_list *n1 = ft_lstnew(s1);
// 	t_list *n2 = ft_lstnew(s2);
// 	ft_lstadd_back(&n1, n2);
// 	printf("%s", (char *)n1->next->content);
// }