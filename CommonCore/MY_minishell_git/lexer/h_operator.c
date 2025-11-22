/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_operator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:05:27 by rchiam            #+#    #+#             */
/*   Updated: 2025/11/22 13:46:19 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

// func: 	handler used in lp_parsedline.c to handle operator
// input:	lp param (see lp_init_clear.c init)
// actions:	increase parsed char based on single or double token
// output:	operator token (see tl_make_new_token)

t_tokenlinkedlist	*h_handle_operator(t_lexer_params *lp)
{
	char				*value;
	t_tokenlinkedlist	*new;

	value = malloc(3 * sizeof(char));
	if (!value)
		return (NULL);
	value[0] = lp->cmdline[lp->i];
	value[2] = '\0';
	if (lp->cmdline[lp->i + 1]
		&& (lp->cmdline[lp->i] == lp->cmdline[lp->i + 1]))
	{
		value[1] = value[0];
		lp->parsed_chars = 2;
	}
	else
	{
		value[1] = '\0';
		lp->parsed_chars = 1;
	}
	new = tl_make_new_token(value, lp->bracketdepth, 0, lp->current);
	return (new);
}
