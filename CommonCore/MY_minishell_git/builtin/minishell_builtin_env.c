/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin_env.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <twtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:43:43 by twtan             #+#    #+#             */
/*   Updated: 2025/11/17 19:43:47 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	minishell_env_handler(t_ms *msp)
{
 	printf("\n env handler '%s'", msp->split_cmd[0]);
}
