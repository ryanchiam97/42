/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:04:51 by twtan             #+#    #+#             */
/*   Updated: 2025/05/10 15:23:24 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Descriptions
Adds the node ’new’ at the beginning of the list.

Arguments
lst: The address of a pointer to the first node of a list.
new: The address of a pointer to the node to be added.
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == 0)
		return ;
	if (*lst != 0)
		ft_lstadd_back(&new, *lst);
	*lst = new;
}
