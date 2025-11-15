#include "minishell.h"

// func: minishell_exit_handler
// handles the builtin command exit
// accepts an integer to return as exit number
// will exit the minishell when executed
void	minishell_exit_handler(t_ms *msp)
{
	ft_printf("exit\n");
	msp->loop = 0;
	msp->exit_nbr = 0;
	if (msp->split_cmd[1] != 0)
	{
		if (ft_atoi_r(msp->split_cmd[1], &(msp->exit_nbr)) == -1)
		{
			msp->exit_nbr = 2;
			ft_printf("minishell: exit: %s: numeric argument required\n",msp->split_cmd[1]);
		}
	}
}