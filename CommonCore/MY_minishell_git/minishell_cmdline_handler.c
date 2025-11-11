/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmdline_handler.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 20:18:08 by twtan             #+#    #+#             */
/*   Updated: 2025/11/05 23:26:27 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// func: minishell_adjust_delimiter
// Add delimiter to the followings control operators token and metacharactors
// redirectors (<, <<, >, >>)
// pipes (|)
// concurrent (&)
//
// remove delimiter
// parenthesis ( (), [] )
// env ($)
void	minishell_adjust_delimiter(t_ms *msp)
{
	int	idx;
	int	new_idx;
	int	add_space_count;
	
	add_space_count = 0;
	idx = -1;
	while (msp->cmdline[++idx] != 0)
	{
		if ((msp->cmdline[idx] == '<') && (msp->cmdline[idx + 1] != '<'))
			add_space_count += 2;
		if ((msp->cmdline[idx] == '>') && (msp->cmdline[idx + 1] != '>'))
			add_space_count += 2;
		if ((msp->cmdline[idx] == '|') && (msp->cmdline[idx + 1] != '|'))
			add_space_count += 2;
	}
	idx = -1;
	new_idx = 0;
	while (msp->cmdline[++idx] != 0)
	{
		
	}
	msp->tmp = 0;
}


/*
int	minishell_cmdline_controls(t_ms *msp)
{

}*/

// func: minishell_cmdline_handler
// Use to parse the command line into different parts
// parse delimits at redirectors, pipes then space and processed in order
int	minishell_cmdline_handler(t_ms *msp)
{
	msp->split_cmd = ft_split_r(msp->cmdline, ' ');
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
	{
		ft_printf("\nenv\n");
	}
	ft_free_split_arr (&msp->split_cmd);
	return (0);
}
