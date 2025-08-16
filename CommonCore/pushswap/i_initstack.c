/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_initstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 15:56:52 by rchiam            #+#    #+#             */
/*   Updated: 2025/08/16 16:12:05 by rchiam           ###   ########.fr       */
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

void	loadstack(t_stack *s, t_stack *other)
{
	s->other = other;
}

void	freestack(t_stack *s)
{
	free(s->arr);
}
