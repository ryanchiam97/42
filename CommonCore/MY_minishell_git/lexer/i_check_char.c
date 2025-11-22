/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_check_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:59:08 by rchiam            #+#    #+#             */
/*   Updated: 2025/11/22 13:18:18 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

// func: 	identify space
// input:	char
// actions:	-
// output:	return 1 or 0

int	i_is_space(char input)
{
	if (input == '\t' || input == ' ')
		return (1);
	else
		return (0);
}

// func: 	identify brackets
// input:	char
// actions:	-
// output:	return 1 or 0

int	i_is_bracket(char input)
{
	if (input == '(' || input == ')')
		return (1);
	else
		return (0);
}

// func: 	identify operator char
// input:	char
// actions:	-
// output:	return 1 or 0

int	i_is_op(char input)
{
	if (input == '|' || input == '<' || input == '>' || input == '&')
		return (1);
	else
		return (0);
}
// func: 	identify quote
// input:	char
// actions:	-
// output:	return 2(") or 1(') or 0

int	i_is_quote(char input)
{
	if (input == '\'')
		return (1);
	else if (input == '\"')
		return (2);
	else
		return (0);
}
