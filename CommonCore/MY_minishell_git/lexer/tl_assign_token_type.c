/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_assign_token_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:51:10 by rchiam            #+#    #+#             */
/*   Updated: 2025/11/22 13:59:48 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

// func: 	return token typ enum based off the char input
//			tl_assign_token_type0
//				tl_assign_token_type1 (for single char)
//				tl_assign_token_type2 (for double char - ie operators)
// input:	char
// actions:	-
// output:	token type enum (see the lexer.h)

t_tokentype	tl_assign_token_type2(char *word)
{
	char	c1;
	char	c2;

	c1 = word[0];
	c2 = word[1];
	if (c1 != c2)
		return (T_WORD);
	if (c1 == '>')
		return (T_APPEND);
	else if (c1 == '<')
		return (T_HEREDOC);
	else if (c1 == '&')
		return (T_AND);
	else if (c1 == '|')
		return (T_OR);
	else
		return (T_WORD);
}

t_tokentype	tl_assign_token_type1(char *word)
{
	char	c1;

	c1 = word[0];
	if (c1 == '|')
		return (T_PIPE);
	else if (c1 == '<')
		return (T_R_IN);
	else if (c1 == '>')
		return (T_R_OUT);
	else if (c1 == '(')
		return (T_LB);
	else if (c1 == ')')
		return (T_RB);
	else if (c1 == '\0')
		return (T_EOF);
	else
		return (T_WORD);
}

t_tokentype	tl_assign_token_type0(char *word)
{
	int	len;

	len = ft_strlen(word);
	if (len == 2)
		return (tl_assign_token_type2(word));
	else if (len == 1)
		return (tl_assign_token_type1(word));
	else
		return (T_WORD);
}
