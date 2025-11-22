/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_bracket.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:04:22 by rchiam            #+#    #+#             */
/*   Updated: 2025/11/22 13:46:09 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

// func: 	handler used in lp_parsedline.c to handle bracket chars
// input:	lp param (see lp_init_clear.c init)
// actions:	increase bracketdepth, parsedchars
// output:	bracket token (see tl_make_new_token)

t_tokenlinkedlist	*h_handle_bracket(t_lexer_params *lp)
{
	t_tokenlinkedlist	*new;

	if (lp->cmdline[lp->i] == '(')
	{
		(lp->bracketdepth)++;
		new = tl_make_new_token(
				ft_strdup("("),
				lp->bracketdepth,
				0,
				lp->current);
	}
	else if (lp->cmdline[lp->i] == ')')
	{
		new = tl_make_new_token(
				ft_strdup(")"),
				lp->bracketdepth,
				0,
				lp->current);
		(lp->bracketdepth)--;
	}
	lp->parsed_chars = 1;
	return (new);
}
