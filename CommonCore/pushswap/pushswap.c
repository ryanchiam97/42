/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 22:01:39 by rchiam            #+#    #+#             */
/*   Updated: 2025/09/30 21:07:29 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	int		*int_arr;
	int		size;
	t_stack	*a;

	if (argc == 1)
		return (0);
	if (checkargvissues(argc - 1, argv + 1))
		return (write(2, "Error\n", 6), -1);
	size = parse(argc, &argv, &int_arr);
	if (size == -1)
		return (write(2, "Error\n", 6), -1);
	if (issorted(int_arr, size))
		return (free(int_arr), 0);
	a = stack_startup(int_arr, size);
	if (size < 2)
		return (freestacksandinput(a, a->other, int_arr), 0);
	else if (size == 2)
		sorttwo(a);
	else if (size == 3)
		sortthree(a);
	else if (size < 6)
		sortfourfive(a);
	else
		globalradixsort(a, determinepower(a->size - 1));
	freestacksandinput(a, a->other, int_arr);
}
/*
Requirements and Scoring

For maximum project validation (100%) and eligibility for bonuses, you must:
◦ Sort 100 random numbers in fewer than 700 operations.
◦ Sort 500 random numbers in no more than 5500 operations.
• For minimal project validation (which implies a minimum grade of 80%), you
can succeed with different averages:
◦ 100 numbers in under 1100 operations and 500 numbers in under
8500 operations
◦ 100 numbers in under 700 operations and 500 numbers in under
11500 operations
◦ 100 numbers in under 1300 operations and 500 numbers in under
5500 operations
*/

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
./push_swap " 12 4 6 8 54fhd 4354"
./push_swap 1 --    45 32
these examples should return "Error\n"

The program should NOT work if it encounters a double number
./push_swap 1 3 58 9 3
./push_swap 3 03
./push_swap " 49 128     50 38   49"
these examples should return "Error\n"

should work with no arg. just return
./push_swap

should just return if alr sorted (of diff lengths)
./push_swap 1 2 3 4 5 6 7

./push_swap "95 99 -9 10 9"
this example should work because -9 & 9 are not equal

The program should work with INT MAX & INT MIN

./push_swap 2147483647 2 4 7
./push_swap 99 -2147483648 23 545
./push_swap "2147483647 843 56544 24394"
these examples should work and sort your list

./push_swap "1 2 4 3" 76 90 "348 05"

./push_swap 54867543867438 3
./push_swap -2147483647765 4 5
./push_swap "214748364748385 28 47 29"
these examples should return "Error\n"

To fix (or check against ./checker_linux):
./push_swap 1 " "  to show error
./push_swap "1 2 4 3" 76 90 "348 05         -" to show error
*/