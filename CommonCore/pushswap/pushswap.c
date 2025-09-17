/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 22:01:39 by rchiam            #+#    #+#             */
/*   Updated: 2025/09/18 00:19:16 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	int		*int_arr;
	int		size;
	t_stack	*a;

	if (argc >= 2)
	{
		size = parse(argc, &argv, &int_arr);
		if (size == -1)
			return (-1);
		a = stack_startup(int_arr, size);
		if (size < 2)
			return (freeallstacksandinput(a, a->other, int_arr), 0);
		else if (size == 2)
			sorttwo(a);
		else if (size == 3)
			sortthree(a);
		else if (size < 6)
			sortfourfive(a);
		else
			globalradixsort(a, determinepower(a->size - 1));
		freeallstacksandinput(a, a->other, int_arr);
	}
}
/*
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
