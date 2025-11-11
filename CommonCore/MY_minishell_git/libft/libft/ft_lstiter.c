/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:39:47 by twtan             #+#    #+#             */
/*   Updated: 2025/05/10 16:52:37 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

Descriptions
Iterates through the list ’lst’ and applies the function ’f’ to the content 
of each node.

Arguments
lst: The address of a pointer to a node.
f: The address of the function to apply to each node’s content.

*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == 0)
		return ;
	while (lst != 0)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}
