/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin_echo.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <twtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:06:46 by twtan             #+#    #+#             */
/*   Updated: 2025/10/30 21:06:51 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
int	minishell_echo_option(char **cmd)
{
	int	option_count;
	int	cmd_idx;

	option_count = 0;
	cmd_idx = -1;
	while 
}
*/

void	minishell_echo_handler(t_ms *msp)
{
	bool	prt_newline;
	int		count;
 
	prt_newline = 1;
	if ((ft_strncmp(msp->split_cmd[1], "-n", 2) == 0) && (msp->split_cmd[1] != 0))
		prt_newline = 0;
	else
		ft_printf("%s", msp->split_cmd[1]);
	count = 1;
	while (msp->split_cmd[++count] != 0)
	{
		// need to expand checks for environment variables and other tokens
		ft_printf("%s", msp->split_cmd[count]);
	}
	if (prt_newline == 1)
		ft_printf("\n");
}
