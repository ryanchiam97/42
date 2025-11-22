/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_quote.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:00:53 by rchiam            #+#    #+#             */
/*   Updated: 2025/11/22 13:46:22 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

// func: 	handler used in lp_parsedline.c to handle str between quotations
//			h_handle_quote
//				handle_quote_helper
// input:	lp param (see lp_init_clear.c init)
// actions:	update the quote level in the token to the matching quote
// output:	word token (see tl_make_new_token)

t_tokenlinkedlist	*handle_quote_helper(t_lexer_params *lp, int counter,
		int quote)
{
	t_tokenlinkedlist	*new;
	char				*value;

	value = malloc(sizeof(char) * counter);
	if (!value)
		return (NULL);
	ft_strlcpy(value, &lp->cmdline[lp->i + 1], counter);
	new = tl_make_new_token(value, lp->bracketdepth, quote, lp->current);
	if (!new)
		return (NULL);
	lp->parsed_chars = counter + 1;
	return (new);
}

t_tokenlinkedlist	*h_handle_quote(t_lexer_params *lp)
{
	int					quote;
	int					counter;
	int					quote_closed;

	quote = i_is_quote(lp->cmdline[lp->i]);
	counter = 1;
	quote_closed = 0;
	while (lp->cmdline[lp->i + counter] != '\0')
	{
		if (quote == i_is_quote(lp->cmdline[lp->i + counter]))
		{
			quote_closed = 1;
			break ;
		}
		counter++;
	}
	if (lp->cmdline[lp->i + counter] == '\0' && quote_closed == 0)
		return (NULL);
	return (h_handle_quote_helper(lp, counter, quote));
}
