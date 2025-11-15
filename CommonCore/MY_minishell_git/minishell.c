/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:45:00 by twtan             #+#    #+#             */
/*   Updated: 2025/11/15 14:53:57 by rchiam           ###   ########.fr       */
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
/*
Allowed external functions:
readline, rl_clear_history, rl_on_new_line,
rl_replace_line, rl_redisplay, add_history,
printf, malloc, free, write, access, open, read,
close, fork, wait, waitpid, wait3, wait4, signal,
sigaction, sigemptyset, sigaddset, kill, exit,
getcwd, chdir, stat, lstat, fstat, unlink, execve,
dup, dup2, pipe, opendir, readdir, closedir,
strerror, perror, 

isatty, ttyname, ttyslot, ioctl,
getenv, tcsetattr, tcgetattr, tgetent, tgetflag,
tgetnum, tgetstr, tgoto, tputs
*/