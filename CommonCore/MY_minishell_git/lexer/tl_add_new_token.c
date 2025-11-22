/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_add_new_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:57:19 by rchiam            #+#    #+#             */
/*   Updated: 2025/11/22 13:57:02 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

// func: 	add new token to the linked list
// input:	new token address and address of ptr to head
// actions:	-
// output:	-

void	tl_add_token(t_tokenlinkedlist **head, t_tokenlinkedlist *newtoken)
{
	t_tokenlinkedlist	*last;

	if (!newtoken)
		return ;
	if (!*head)
	{
		*head = newtoken;
		return ;
	}
	last = tl_get_last(*head);
	last->next = newtoken;
	newtoken->previous = last;
	return ;
}
