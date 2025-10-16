/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:30:49 by rchiam            #+#    #+#             */
/*   Updated: 2025/05/12 16:06:02 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*temp;

// 	temp = *lst;
// 	while (temp->next != NULL)
// 	{
// 		temp = temp->next;
// 	}
// 	temp->next = new;
// }

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

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

// int	main(void)
// {
// 	char	*s1;
// 	t_list	*n1;
// 	char	*s2;
// 	t_list	*n2;
// 	char	*s3;
// 	t_list	*n3;

// 	s1 = "1 \n";
// 	n1 = ft_lstnew(s1);
// 	s2 = "2 \n";
// 	n2 = ft_lstnew(s2);
// 	s3 = "3 \n";
// 	n3 = ft_lstnew(s3);
// 	ft_lstadd_back(&n1, n2);
// 	ft_lstadd_back(&n1, n3);
// 	printf("last node is %s", (char *)ft_lstlast(n1)->content);
// }
