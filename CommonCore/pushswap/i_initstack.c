/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_initstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 15:56:52 by rchiam            #+#    #+#             */
/*   Updated: 2025/09/19 20:43:31 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*initstack(int *arr, char name, int size, int maxsize)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->arr = malloc(sizeof(int) * maxsize);
	if (!s->arr)
		return (NULL);
	if (s->arr)
		ft_memcpy(s->arr, arr, sizeof(int) * size);
	s->size = size;
	s->name = name;
	assign_ops(s);
	return (s);
}

void	assign_ops(t_stack *s)
{
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
}

void	loadotherstack(t_stack *s, t_stack *other)
{
	s->other = other;
}

void	freestacksandinput(t_stack *a, t_stack *b, int *intarr)
{
	free(a->arr);
	free(a);
	free(b->arr);
	free(b);
	free(intarr);
}

t_stack	*stack_startup(int *arr, int max_size)
{
	t_stack	*a;
	t_stack	*b;
	int		*intarr;

	intarr = NULL;
	a = initstack(arr, 'a', max_size, max_size);
	b = initstack(intarr, 'b', 0, max_size);
	loadotherstack(a, b);
	loadotherstack(b, a);
	return (a);
}
