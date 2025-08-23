/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 22:01:39 by rchiam            #+#    #+#             */
/*   Updated: 2025/08/23 18:37:13 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char** argv)
{
	int		*int_arr;
	int		size;
	t_stack	*a;

	size = parsehandler(argc, argv, int_arr);
	a = stack_startup(int_arr, size);
	if (size < 2)
		return (0);
	else if (size == 2)
		sorttwo(a);
	else if (size == 3)
		sortthree(a);
	else if (size < 6)
		sortfourfive(a);
	else
		radixsort(a, determinepower(size - 1));
	freeallstacks(a);
}
/*
To do:
*/

/*
*** Radix way ***
1. convert all to indexes (or just find smallest number - if -ve, add that to all)
2. convert all to binary
3. recursesplit
	base case: if < 3, sort 3
	if 0x,
		b push to a
		recursesplit0xx
	merge
		
	if 1x,	
		a push to b
		recursesplit1xx

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
