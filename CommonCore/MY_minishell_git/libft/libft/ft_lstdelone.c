/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:34:14 by twtan             #+#    #+#             */
/*   Updated: 2025/05/10 16:12:20 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Descriptions
Takes a node as parameter and frees its content using the function ’del’.
Free the node itself but does NOT free the next node.

Arguments
lst: The node to free.
del: The address of the function used to delete the content.

*/

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if ((lst == 0) || (del == 0))
		return ;
	del(lst -> content);
	free(lst);
}
