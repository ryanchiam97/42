/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_make_new_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:49:08 by rchiam            #+#    #+#             */
/*   Updated: 2025/11/22 14:06:29 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

// func: 	takes in various inputs needed to make a token
// input:	string value, bracketdepth, quotetype, prev token addr
// actions:	malloc new node,
//			inputs parameters, determines type from value
// 			check: heredoc delim, expansionchars
//			note done: space_before_token has to be filled outside this loop
// output:	token addr

t_tokenlinkedlist	*tl_make_new_token(char *value, int bracketdepth,
		int quotetype, t_tokenlinkedlist *prev)
{
	t_tokenlinkedlist	*newnode;

	newnode = malloc(sizeof(t_tokenlinkedlist));
	if (!newnode)
		return (NULL);
	newnode->value = value;
	newnode->type = tl_assign_token_type0(value);
	newnode->bracket_depth = bracketdepth;
	newnode->has_space_before = 0;
	newnode->quotetype = quotetype;
	if (!prev)
		newnode->previous = NULL;
	else
		newnode->previous = prev;
	newnode->next = NULL;
	if (prev && prev->type == T_HEREDOC)
		newnode->is_heredoc_delim = 1;
	else
		newnode->is_heredoc_delim = 0;
	if (newnode->type == T_WORD && newnode->quotetype != 1
		&& newnode->is_heredoc_delim == 0)
		newnode->expand_later = tl_check_expansion(value);
	else
		newnode->expand_later = 0;
	return (newnode);
}
