/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_stringhandler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 23:04:43 by rchiam            #+#    #+#             */
/*   Updated: 2025/08/22 20:50:49 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
int check_string(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (
				(ft_isalum(str[i]) && !ft_isdigit(str[i])) 
				||(str[i+1] 
				&& (str[i] == '-' || str[i] == '+') 
				&& (
					(str[i+1] == '-' || str[i+1] == '+') 
					|| 
					!ft_isdigit(str[i+1])
					)
				)
			)
			return (0);
		i++;
	}
}

char *addstring(char *main, char *new)
{
	char *temp;

	if (!main || !new)
		return (NULL);
	temp = main;
	main = ft_strjoin(temp, " ");
	free(temp);
	temp = main;
	main = ft_strjoin(temp, new);
	free(temp);
	return (main);
}

int checkdupes(int *int_arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size -1)
	{
		j = i + 1;
		while (j < size)
		{
			if (int_arr[i] == int_arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/* 
Error Checklist

The program must work with several numerical arguments
./push_swap 1 3 5 +9 20 -4 50 60 04 08

The program also works if you receive a single character list as a parameter
./push_swap "3 4 6 8 9 74 -56 +495"

The program should NOT work if it encounters another character
./push_swap 1 3 dog 35 80 -3
./push_swap a
./push_swap 1 2 3 5 67b778 947
.push_swap " 12 4 6 8 54fhd 4354"
./push_swap 1 --    45 32
these examples should return "Error\n"

The program should NOT work if it encounters a double number
./push_swap 1 3 58 9 3
./push_swap 3 03
./push_swap " 49 128     50 38   49"
these examples should return "Error\n"

./push_swap "95 99 -9 10 9"
this example should work because -9 & 9 are not equal

The program should work with INT MAX & INT MIN

./push_swap 2147483647 2 4 7
./push_swap 99 -2147483648 23 545
./push_swap "2147483647 843 56544 24394"
these examples should work and sort your list

./push_swap 54867543867438 3
./push_swap -2147483647765 4 5
./push_swap "214748364748385 28 47 29"
these examples should return "Error\n"

Nothing has been specified when strings and int are mixed. It's up to you what you want to do
./push_swap "1 2 4 3" 76 90 "348 05"
*/