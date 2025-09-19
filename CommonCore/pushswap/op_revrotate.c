/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:32:44 by rchiam            #+#    #+#             */
/*   Updated: 2025/09/19 20:30:46 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	revrotate(t_stack *s)
{
	int	last;

	last = s->arr[s->size - 1];
	ft_memmove(s->arr + 1, s->arr, (s->size - 1) * sizeof(int));
	(s->arr)[0] = last;
}

void	rra(t_stack *a)
{
	revrotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	revrotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	revrotate(a);
	revrotate(b);
	write(1, "rrr\n", 4);
}
