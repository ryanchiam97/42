/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:30:11 by rchiam            #+#    #+#             */
/*   Updated: 2025/09/06 17:11:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	swap(t_stack *s)
{
	int	tmp;

	if (s->size < 2)
		return (0);
	tmp = s->arr[0];
	s->arr[0] = s->arr[1];
	s->arr[1] = tmp;
	// updateminmax(s);
	return (1);
}

void	sa(t_stack *a)
{
	if (swap(a))
		write(1, "sa\n", 3);
	// printout_stack_info(a);
}

void	sb(t_stack *b)
{
	if (swap(b))
		write(1, "sb\n", 3);
	// printout_stack_info(b->other);
}

void	ss(t_stack *a, t_stack *b)
{
	int	_sa;
	int	_sb;

	_sa = swap(a);
	_sb = swap(b);
	if (_sa && _sb)
		write(1, "ss\n", 3);
	else if (_sa == 1 && _sb == 0)
		sa(a);
	else if (_sa == 0 && _sb == 1)
		sb(b);
	// printout_stack_info(a);
}
