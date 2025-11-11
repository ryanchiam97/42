/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:44:27 by twtan             #+#    #+#             */
/*   Updated: 2025/05/12 15:07:58 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Descriptions
Deletes and frees the given node and all its successors, using the function ’del’
and free.
Finally, set the pointer to the list to NULL.

Arguments
lst: The address of a pointer to a node.
del: The address of the function used to delete the content of the node.

*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if ((lst == 0) && (del == 0))
		return ;
	if (*lst == 0)
		return ;
	while (*lst != 0)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}
