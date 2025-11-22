/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_space.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:06:30 by rchiam            #+#    #+#             */
/*   Updated: 2025/11/22 13:15:03 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

// func: 	handler used in lp_parsedline.c to handle space
// input:	lp param (see lp_init_clear.c init)
// actions:	increase the parsed chars to bypass the spaces
// output:	-

void	h_handle_space(t_lexer_params *lp)
{
	int	count;

	count = 0;
	while (i_is_space(lp->cmdline[lp->i + count]))
		count++;
	lp->parsed_chars = count;
}
