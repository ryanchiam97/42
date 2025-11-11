/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <twtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:45:00 by twtan             #+#    #+#             */
/*   Updated: 2025/10/30 15:45:02 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Minishell
#include "minishell.h"

int	g_signal;

// func: main
// main entry point for project minishell
// loop readline to handle command line
int	main(void)
{
	t_ms	msp;

	g_signal = 0;
	signal(SIGINT, minishell_signal_handler);
	signal(SIGTERM, minishell_signal_handler);
	msp.self_pid = getpid();
	msp.loop = 1;
	while(msp.loop)
	{
		msp.cmdline = readline("😄:");	
		//msp.cmdline = ft_readline("😄:");
		if (msp.cmdline != 0)
			minishell_cmdline_handler(&msp);
		if (msp.cmdline != 0)
			free(msp.cmdline);
		if (g_signal != 0)
			msp.loop = 0;
	}
	get_next_line(-1);
	return (msp.exit_nbr);
}
