/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:33:15 by rchiam            #+#    #+#             */
/*   Updated: 2025/09/06 17:11:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(t_stack *s)
{
	int	first;

	first = s->arr[0];
	ft_memmove(s->arr, s->arr + 1, (s->size - 1) * sizeof(int));
	(s->arr)[s->size - 1] = first;
	// updateminmax(s);
}

void	ra(t_stack *a)
{
	rotate(a);
	write(1, "ra\n", 3);
	// printout_stack_info(a);
}

void	rb(t_stack *b)
{
	rotate(b);
	write(1, "rb\n", 3);
	// printout_stack_info(b->other);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	// printout_stack_info(a);
}
