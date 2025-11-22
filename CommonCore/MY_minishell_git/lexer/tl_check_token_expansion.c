/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_check_token_expansion.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:53:04 by rchiam            #+#    #+#             */
/*   Updated: 2025/11/22 14:01:28 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

// func: 	check if the string has expansion characters $ or *
// input:	string
// actions:	-
// output:	1 or 0

int	tl_check_expansion(char *value)
{
	int	i;
	int	expansion;

	i = 0;
	expansion = 0;
	while (value[i])
	{
		if (value[i] == '$' || value[i] == '*')
			expansion = 1;
		i++;
	}
	return (expansion);
}
