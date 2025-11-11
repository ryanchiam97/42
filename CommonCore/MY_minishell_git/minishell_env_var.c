/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_env_var.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <twtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 20:18:08 by twtan             #+#    #+#             */
/*   Updated: 2025/10/30 20:18:10 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// $[] - arithmetic number operation e.g echo $[2+3] prints 5
// $(cmd) - silent execute the command inside () and output any stdout
//          usage example : arg=$(seq 1000)
// $name - get the value of the varable name
// $? - the most recent exit code
// $$ - 'echo $$' returns the current PID of the shell
// $! - 'echo $$' returns the PID of the background program
// $- - 'echo $-' returns the current setting of the shell 
// $_ - 'echo $_' returns the last argument of the previous command executed

void	minishell_get_env_var(t_ms *msp)
{

}
