/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_initstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 15:56:52 by rchiam            #+#    #+#             */
/*   Updated: 2025/08/23 18:30:01 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*initstack(int *arr, char name, int size, int maxsize)
{
	t_stack	stack;
	t_stack	*s;

	s = &stack;
	s->arr = malloc(sizeof(int) * maxsize);
	s->size = size;
	s->name = name;
	if (s->name == 'a')
	{
		s->swap = sa;
		s->rotate = ra;
		s->revrotate = rra;
		s->push_to_other = pb;
		s->push_to_self = pa;
	}
	else
	{
		s->swap = sb;
		s->rotate = rb;
		s->revrotate = rrb;
		s->push_to_other = pa;
		s->push_to_self = pb;
	}
	return (s);
}

void	loadotherstack(t_stack *s, t_stack *other)
{
	s->other = other;
}

void	freeallstacks(t_stack *s)
{
	free(s->other->arr);
	free(s->other);
	free(s->arr);
	free(s);
}

t_stack	*stack_startup(int *arr, int max_size)
{
	t_stack	*a;
	t_stack	*b;
	int		*intarr;

	a = initstack(arr, 'a', max_size, max_size);
	b = initstack(intarr, 'b', 0, max_size);
	loadotherstack(a, b);
	loadotherstack(b, a);
	return (a);
}
