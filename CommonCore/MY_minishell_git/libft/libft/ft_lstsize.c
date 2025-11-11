/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:16:54 by twtan             #+#    #+#             */
/*   Updated: 2025/05/10 15:21:21 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Descriptions
Counts the number of nodes in the list.

Argument
lst: The beginning of the list.

Return
The length of the list.

*/
int	ft_lstsize(t_list *lst)
{
	size_t	count;

	if (lst == 0)
		return (0);
	count = 1;
	while (lst -> next != 0)
	{
		lst = lst -> next;
		count++;
	}
	return (count);
}
