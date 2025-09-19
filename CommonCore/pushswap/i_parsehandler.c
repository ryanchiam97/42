/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_parsehandler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 23:04:43 by rchiam            #+#    #+#             */
/*   Updated: 2025/09/19 22:09:51 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	checkdupes(int *int_arr, int size)
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

char	*safeaddstring(char *main, char *new)
{
	char	*temp;
	char	*temp2;

	if (!main || !new)
		return (NULL);
	temp = ft_strjoin(main, " ");
	if (!temp)
		return (free(main), NULL);
	temp2 = ft_strjoin(temp, new);
	free(main);
	free(temp);
	if (!temp2)
		return (NULL);
	return (temp2);
}

int	check_string(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 0 || (ft_strlen(str) == 1 && !ft_isdigit(str[i])))
		return (0);
	if (weirdending(str))
		return (0);
	while (str[i])
	{
		if (
			(!ft_isdigit(str[i]) && ft_isalnum(str[i]))
			|| (str[i + 1] && (str[i] == '-' || str[i] == '+')
				&& ((str[i + 1] == '-' || str[i + 1] == '+')
					|| !ft_isdigit(str[i + 1])
				)
			)
			|| ((str[i] == '-' || str[i] == '+')
				&& (i >= 1)
				&& str[i - 1]
				&& ft_isdigit(str[i - 1]))
		)
			return (0);
		i++;
	}
	return (1);
}

int	parse_int_arr(char **str, int *sizeadr, int ***r_arr)
{
	int	*int_arr;

	if (check_string(*str))
		int_arr = parseinput(*str, sizeadr);
	else
		return (0);
	if (!int_arr)
		return (0);
	index_arr(&int_arr, *sizeadr);
	if (checkdupes(int_arr, *sizeadr))
	{
		**r_arr = int_arr;
		return (1);
	}
	else
		return (free(int_arr), 0);
}

int	parse(int argcount, char ***args, int **return_array)
{
	int		i;
	char	*str;
	int		size;

	str = ft_strdup((*args)[1]);
	if (!str)
		return (-1);
	size = -1;
	i = 2;
	while (i < argcount)
	{
		str = safeaddstring(str, (*args)[i]);
		if (!str)
			return (-1);
		i++;
	}
	if (parse_int_arr(&str, &size, &return_array))
		return (free(str), size);
	else
		return (free(str), -1);
}

/*
Error Checklist
(DONE)
The program must work with several numerical arguments
./push_swap 1 3 5 +9 20 -4 50 60 04 08

The program also works if you receive a single character list as a parameter
./push_swap "3 4 6 8 9 74 -56 +495"

The program should NOT work if it encounters another character
./push_swap 1 3 dog 35 80 -3
./push_swap a
./push_swap 1 2 3 5 67b778 947
./push_swap " 12 4 6 8 54fhd 4354"
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

./push_swap "1 2 4 3" 76 90 "348 05"

(NOT DONE)
./push_swap 54867543867438 3
./push_swap -2147483647765 4 5
./push_swap "214748364748385 28 47 29"
these examples should return "Error\n"

./push_swap 1 " "  to show error
*/