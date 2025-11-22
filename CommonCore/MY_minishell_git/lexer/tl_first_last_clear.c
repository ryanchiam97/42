/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_first_last_clear.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:55:09 by rchiam            #+#    #+#             */
/*   Updated: 2025/11/22 14:03:18 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

// func: 	return token address. first in linked list
// input:	token address of token in list
// actions:	-
// output:	token address

t_tokenlinkedlist	*tl_get_first(t_tokenlinkedlist *node)
{
	if (!node)
		return (NULL);
	while (node->previous != NULL)
		node = node->previous;
	return (node);
}

// func: 	return token address. last in linked list
// input:	token address of token in list
// actions:	-
// output:	token address

t_tokenlinkedlist	*tl_get_last(t_tokenlinkedlist *head)
{
	if (!head)
		return (NULL);
	while (head->next != NULL)
		head = head->next;
	return (head);
}
// func: 	clear token linked list
// input:	token address of token in list
// actions:	free list and contents
// output:	-

void	tl_clear_list(t_tokenlinkedlist *list)
{
	t_tokenlinkedlist	*tmp;

	while (list)
	{
		tmp = list->next;
		if (list->value)
			free(list->value);
		free(list);
		list = tmp;
	}
}
