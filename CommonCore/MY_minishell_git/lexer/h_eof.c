/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_eof.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:08:13 by rchiam            #+#    #+#             */
/*   Updated: 2025/11/22 13:46:16 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

// func: 	handler used in lp_parsedline.c to handle eof
// input:	lp param (see lp_init_clear.c init)
// actions:	return error if bracketdepth != 0 and EOF 
// output:	eof token (see tl_make_new_token)

t_tokenlinkedlist	*h_handle_eof(t_lexer_params *lp)
{
	t_tokenlinkedlist	*new;

	if (lp->bracketdepth != 0)
		return (NULL);
	new = malloc(sizeof(t_tokenlinkedlist));
	if (!new)
		return (NULL);
	new->bracket_depth = 0;
	new->expand_later = 0;
	new->is_heredoc_delim = 0;
	new->next = NULL;
	new->previous = lp->current;
	new->quotetype = 0;
	new->type = T_EOF;
	new->value = ft_strdup("EOF");
	return (new);
}
