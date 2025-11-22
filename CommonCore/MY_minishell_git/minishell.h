/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:49:09 by twtan             #+#    #+#             */
/*   Updated: 2025/11/15 14:36:08 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

extern int g_signal;

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "libft/ft_printf.h"
#include "ft_split_r/ft_split_r.h"
#include "ft_readline/ft_readline.h"
#include <readline/readline.h>	// readline
#include <readline/history.h>	// rl_clear_history
#include <curses.h>		// tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
#include <term.h>
#include <termios.h>
#include <signal.h>

typedef struct s_vars
{
	char	*name;
	char	*val;
	void	*next;
}	t_vars;

typedef struct s_minishell
{
	char	*env_vars;
	char	*cmdline;
	char	*tmp;
	char	**split_cmd;
	char	**tmp_arr;
	int		exit_nbr;
	int		self_pid;
	char	loop;
}	t_ms;

// minishell_cmdline_handler.c
int	minishell_cmdline_handler(t_ms *msp);

// minishell_signal_handler.c
void	minishell_signal_handler(int sigcode);

// All built in command handlers
// minishell_builtin_echo.c
void	minishell_echo_handler(t_ms *msp);

// minishell_builtin_exit.c
void	minishell_exit_handler(t_ms *msp);

// minishell_builtin_pwd.c
void	minishell_pwd_handler(void);

// minishell_builtin_env.c
void	minishell_env_handler(t_ms *msp);

#endif
