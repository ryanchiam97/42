/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin_cd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:41:57 by rchiam            #+#    #+#             */
/*   Updated: 2025/11/15 14:46:09 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// To do list
// to handle permission access
// to handle error number

// func: minishell_cd_handler
// handle the change directory request
// chdir returns != 0 when there is fault
// 
int	minishell_cd_handler(t_ms *msp)
{
	int	retval;
	
 	retval = chdir(msp->tmp);
 	
 	// interim error handle
 	if (retval != 0)
 	{
 		printf ("\ncd: %s: %s", strerror(errno), msp->tmp);
 	}
 	return (0);
}

// test function
#include <stdio.h>
int	main(int argc, char **argv)
{
	t_ms 	msp;
	char	buffer[1024];
	
	if (argc != 2)
		printf("\n Please provide argument.\n");
	if (argc != 2)
		return (0);
	printf("\n argv : '%s'\n", argv[1]);
	
	if (getcwd(buffer , 1024) == 0)
	{
		printf("\n Fault : getcwd return 0. \n");
	}
	printf ("\n directory before change: '%s'", buffer);
	
	msp.tmp = argv[1];
	minishell_cd_handler(&msp);
	
	if (getcwd(buffer , 1024) == 0)
	{
		printf("\n Fault : getcwd return 0. \n");
	}
	printf ("\n directory after change: '%s'", buffer);	
	return (0);
}
