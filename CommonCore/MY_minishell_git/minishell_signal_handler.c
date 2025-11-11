/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_signal_handler.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <twtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 20:12:49 by twtan             #+#    #+#             */
/*   Updated: 2025/10/30 20:13:29 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell_signal_handler(int sigcode)
{
	if (sigcode == SIGINT)
	{
		g_signal = sigcode;
		ft_printf("\n");
	}
	if (sigcode == SIGTERM)
	{
		g_signal = sigcode;
		ft_printf("\nTermination Signal\n");
	}
}
