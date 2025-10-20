/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:32:47 by rchiam            #+#    #+#             */
/*   Updated: 2025/05/28 22:13:11 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*temp;

	newlist = NULL;
	if (!f || !del)
		return (NULL);
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (temp == NULL)
			ft_lstclear(&temp, del);
		ft_lstadd_back(&newlist, temp);
		lst = lst->next;
	}
	return (newlist);
}
