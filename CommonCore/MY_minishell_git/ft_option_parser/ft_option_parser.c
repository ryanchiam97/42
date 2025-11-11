/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_option_parser.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <twtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 22:31:46 by twtan             #+#    #+#             */
/*   Updated: 2025/11/05 22:31:48 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option_parser.h"

// func: minishell_option_parser
// parse for all the valid option (single charactor) and return as bits activation
// e.g. echo , valid options are -n -e -E
// call this function "minishell_option_parser("neE", cmdline);"
// if -ne then return bit will be 110
// if -e then return bit will be 010
// if -n then return bit will be 100
// if -nn then return bit will be 100
int	ft_option_parser(char *valid_options, char *cmdline)
{
	int	bits_flag;
	int	idx;
	int	options_len;
	char	*pos;
	
	bits_flag = 0;
	idx = 0;
	if ((cmdline == 0) || (valid_options == 0))
		return (0);
	if ((*cmdline == 0) || (*valid_options == 0))
		return (0);
	options_len = 0;
	while (valid_options[options_len] != 0)
		options_len++;
	while ((cmdline[idx] != '-') && (cmdline[idx] != 0))
		idx++;
	if (cmdline[idx++] != '-')
		return (0);
	while ((cmdline[idx] != ' ') && (cmdline[idx] != 0))
	{
		pos = ft_strchr(valid_options, cmdline[idx++]);
		if (pos != 0)
			bits_flag |= 1 << (options_len - 1 - (int)(pos - valid_options));
		else
			return (0);
	}
	return (bits_flag);
}

/*
// Test function for minishell_option_parser
// to be comment-out when not doing standalone testing
//
// need to compile with libft 
// cc minishell_option_parser.c libft/libftprintf.a
//
int	main(int argc, char **argv)
{
	int	bits_flag;
	int	count;

	if (argc != 3)
	{
		ft_printf("\n Usage");
		ft_printf("\n ./a.out <valid options> <test string maybe with options>");
		ft_printf("\n\n Example");
		ft_printf("\n ./a.out neE -nE");
		return (0);
	}
	ft_printf("\n valid options '%s'", argv[1]);
	ft_printf("\n test string '%s'", argv[2]);
	bits_flag = ft_option_parser(argv[1], argv[2]);
	count = 8;
	ft_printf("\n'");
	while (--count >= 0)
		ft_printf("%d", (bits_flag >> count) % 2);
	ft_printf("'\n");
	return (0);
	
}*/
