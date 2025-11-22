/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmdline_handler.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 20:18:08 by twtan             #+#    #+#             */
/*   Updated: 2025/11/19 23:56:04 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// func: minishell_cmdline_double_quotes_count
// Characters within double quotes are treated as whole string except 
// $ variables which will be expanded later
// splits at double quotes
// restore double quotes to null 
int	minishell_cmdline_double_quotes(t_ms *msp)
{
	int	count;
	int	idx;
	
	count = 0;
	idx = -1;
	while (msp->cmdline[++idx] != 0)
	{
		if (msp->cmdline[idx] == '\"')
		{
			if (idx == 0)
				count++;
			else if (msp->cmdline[idx - 1] != '\\')
				count++;
		}
	}
	if (count % 2 != 0)
		return (count);
	msp->split_cmd = ft_split_r(msp->cmdline, '"');
	
	// dq restoration needed
	
	return (count);
}

// func : pipe handler


// func: minishell_cmdline_handler
// Use to parse the command line into different parts
// parse delimits at redirectors, pipes then space and processed in order
int	minishell_cmdline_handler(t_ms *msp)
{
	// pre-split for strings, any meta-characters and operators are ignore 
	// in string (except expansion which to be handle later)
	msp->split_cmd = ft_split_r(msp->cmdline, '"');
	
	msp->split_cmd = ft_split_r(msp->cmdline, '|');
	
	// pipe handler
	
	// minishell_cmdline_double_quotes(msp);
	
	if ((ft_strncmp(msp->split_cmd[0], "exit", 4) == 0) && (msp->split_cmd[0] != 0))
		minishell_exit_handler(msp);
	if ((ft_strncmp(msp->split_cmd[0], "echo", 4) == 0) && (msp->split_cmd[0] != 0))
		minishell_echo_handler(msp);
	if ((ft_strncmp(msp->split_cmd[0], "cd", 2) == 0) && (msp->split_cmd[0] != 0))
	{
		ft_printf("cd\n");
	}
	if ((ft_strncmp(msp->split_cmd[0], "pwd", 3) == 0) && (msp->split_cmd[0] != 0))
		minishell_pwd_handler();
	if ((ft_strncmp(msp->split_cmd[0], "export", 6) == 0) && (msp->split_cmd[0] != 0))
	{
		ft_printf("\nexport\n");
	}
	if ((ft_strncmp(msp->split_cmd[0], "unset", 5) == 0) && (msp->split_cmd[0] != 0))
	{
		ft_printf("\nunset\n");
	}
	if ((ft_strncmp(msp->split_cmd[0], "env", 3) == 0) && (msp->split_cmd[0] != 0))
		minishell_env_handler(msp);
	ft_free_split_arr (&msp->split_cmd);
	return (0);
}
