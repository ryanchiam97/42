/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_word.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:07:23 by rchiam            #+#    #+#             */
/*   Updated: 2025/11/22 13:46:28 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

// func: 	handler used in lp_parsedline.c to handle word until space delim
// input:	lp param (see lp_init_clear.c init)
// actions:	-
// output:	word token (see tl_make_new_token)

t_tokenlinkedlist	*h_handle_word(t_lexer_params *lp)
{
	int					j;
	char				*value;
	t_tokenlinkedlist	*new;

	j = 0;
	while (lp->cmdline[lp->i + j] != '\0'
		&& !i_is_space(lp->cmdline[lp->i + j])
		&& !i_is_quote(lp->cmdline[lp->i + j])
		&& !i_is_bracket(lp->cmdline[lp->i + j])
		&& !i_is_op(lp->cmdline[lp->i + j]))
		j++;
	value = malloc(sizeof(char) * (j + 1));
	if (!value)
		return (NULL);
	ft_strlcpy(value, &lp->cmdline[lp->i], j + 1);
	new = tl_make_new_token(value, lp->bracketdepth, 0, lp->current);
	if (!new)
		return (NULL);
	lp->parsed_chars = j;
	return (new);
}
