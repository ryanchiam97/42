/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_parsecmdline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:46:03 by rchiam            #+#    #+#             */
/*   Updated: 2025/11/22 13:55:26 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

// func: 	main loop that turns cmd line into token linked list
//			lp_parsecmdline
//				lp_init_lexer_params
//				while (going through cmdline)
//					setupflags
//					handlecmdlinechar
//						h_*.c and i_*.c handlers and identifiers
//					tk_add_token.c and update i/parsedchars
//				handle eof, lp_clear_lexer_params
// input:	cmdline as single string
// actions:	tokenize in single pass. 
//			Handle state using handlers and lexer params.
//			Input the tokens w as much information as possible for later 
// output:	token linked list

void	setupflags(t_lexer_params *lp, int *space_bef, int *new, int *space)
{
	*space_bef = 0;
	if (lp->cmdline[lp->i - 1] && i_is_space(lp->cmdline[lp->i -1]))
		*space_bef = 1;
	lp->parsed_chars = 0;
	*space = 0;
	*new = NULL;
}

void	handlecmdlinechar(t_lexer_params *lp, int *new, int *space)
{
	if (i_is_quote(lp->cmdline[lp->i]))
		*new = (h_handle_quote(lp));
	else if (i_is_bracket(lp->cmdline[lp->i]))
		*new = (h_handle_bracket(lp));
	else if (i_is_op(lp->cmdline[lp->i]))
		*new = (h_handle_operator(lp));
	else if (i_is_space(lp->cmdline[lp->i]))
	{
		h_handle_space(lp);
		*space = 1;
	}
	else
		*new = h_handle_word(lp);
}

t_tokenlinkedlist	*lp_parsecmdline(char *cmdline)
{
	t_lexer_params		*lp;
	t_tokenlinkedlist	*new;
	t_tokenlinkedlist	*list;
	int					space;
	int					space_before_token;

	lp = lp_init_lexer_params(cmdline);
	if (!lp)
		return (NULL);
	while (lp->cmdline[lp->i] != '\0')
	{
		setupflags(lp, &space_before_token, &new, &space);
		handlecmdlinechar(lp, &new, &space);
		if (!new && space == 0)
			return (tl_clear_list(lp->head), lp_clear_lexer_params(lp), NULL);
		if (new)
			new->has_space_before = space_before_token;
		tl_add_token(&lp->head, new);
		lp->i += lp->parsed_chars;
		lp->current = tl_get_last(lp->head);
	}
	new = h_handle_eof(lp);
	tl_add_token(&lp->head, new);
	list = lp->head;
	return (lp_clear_lexer_params(lp), list);
}
