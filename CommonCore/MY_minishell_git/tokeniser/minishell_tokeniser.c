/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_tokeniser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <twtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:34:24 by twtan             #+#    #+#             */
/*   Updated: 2025/11/20 16:34:29 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell_tokeniser.h"

// func: tokeniser_double_quote_precount
// Determine the double quote count is correct
// Argument 
// str : input string to parse for double quote
// valid : use as an indicator if the check is good
// 	   1 - good, double quote count is zero or even number
// 	   -1 - fail, double quote count is odd number
// Return : the number of double quote count (count) in string (str)
int	tokeniser_double_quote_precount(char *str, int *valid)
{
	int	idx;	// general index
	int	count;	// 
	
	// step through the string to search for double quote
	idx = -1;
	count = 0;
	while (str[++idx] != 0)
	{
		if (str[idx] == '\"')	// if this charactor is a double quote
			count++;	// increement count if double quote
	}
	
	// check if the double quote count is even
	*valid = -1;			// by default, set (valid) as fail
	if (count % 2 == 0)		// if (count) is even, set (valid) as good
		*valid = 1;
	return (count);
}


// func: tokeniser_double_quote_restore
// Restore the double quote to its original position
static int	*tokeniser_double_quote_restore (char *str, char **arr, int *valid)
{
	int	idx;			// general index;
	int	arr_idx;		// array index;

	idx = -1;
	arr_idx = 0;
	while (str[++idx] != 0)
	{
		if(str[idx] == '\"')
		{
			
		}
	}
}

// func: minishell_tokeniser
// Take in the command line string and parse it into different section
char	**minishell_tokeniser(char *str, int *valid)
{
	char	**arr;
	int	count;
	
	// precount the double quote
	count = tokeniser_double_quote_precount(str, valid);
	if (*valid != 1)
		return (0);
	
	// pre-split for strings, any meta-characters and operators are ignore 
	// in string (except expansion which to be handle later)
	arr = ft_split_r(str, '"');
	
	// string delimiter restoration
	
	
	//msp->split_cmd = ft_split_r(msp->cmdline, '"');
	
	//msp->split_cmd = ft_split_r(msp->cmdline, '|');
	return (arr);
}

// test functions
#include <stdio.h>
int	main(int argc, char **argv)
{
	char	**arr;
	int	valid;
	int	idx;
	
	if (argc != 2)
	{
		printf("\n Please provide a string for parsing.");
		return (0);
	}
	
	// call the tokeniser
	arr = minishell_tokeniser(argv[1], &valid);
	if (valid != 1)
	{
		printf ("\n Double quote did not close.\n");
		return (0);
	}
	
	// display the content of the array
	idx = -1;
	printf("\n content view");
	while (arr[++idx] != 0)
		printf("\n [%d] : '%s'", idx, arr[idx]);
	printf("\n");
	// free array
	ft_free_split_arr(&arr);
	return (0);
}

