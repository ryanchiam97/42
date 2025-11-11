/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:31:53 by twtan             #+#    #+#             */
/*   Updated: 2025/05/10 15:03:04 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Descriptions
Allocates memory and returns a new node. 
The ’content’ member variable is initialized with the given parameter ’content’.
The variable ’next’ is initialized to NULL.

Arguments
content: The content to store in the new node.

Returns
A pointer to the new node
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list) * 1);
	if (tmp == 0)
		return (0);
	tmp -> content = content;
	tmp -> next = 0;
	return (tmp);
}
