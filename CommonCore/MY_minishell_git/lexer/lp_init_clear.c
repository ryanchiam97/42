/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_init_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:18:06 by rchiam            #+#    #+#             */
/*   Updated: 2025/11/22 13:20:11 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

// func: 	init params for lexer parser to be passed around (see lexer.h)
// input:	cmdline as single string
// actions:	init lp
// output:	lp

t_lexer_params	*lp_init_lexer_params(char *cmdline)
{
	t_lexer_params	*l_params;

	l_params = malloc(sizeof(t_lexer_params));
	if (!l_params)
		return (NULL);
	l_params->cmdline = ft_strdup(cmdline);
	if (!l_params->cmdline)
	{
		free(l_params);
		return (NULL);
	}
	l_params->i = 0;
	l_params->bracketdepth = 0;
	l_params->parsed_chars = 0;
	l_params->head = NULL;
	l_params->current = NULL;
	return (l_params);
}

// func: 	free lexer params object and contents
// input:	lp param (see lp_init_clear.c init)
// actions:	free stuff
// output:	-

void	lp_clear_lexer_params(t_lexer_params *lp)
{
	free(lp->cmdline);
	free(lp);
}
