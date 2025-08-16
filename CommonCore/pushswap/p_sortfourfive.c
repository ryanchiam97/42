/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_sortfourfive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 22:35:23 by rchiam            #+#    #+#             */
/*   Updated: 2025/08/16 16:20:49 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_smallest_index(t_stack *s)
{
	int	i;
	int	smallest;
	int	smallestindex;

	i = 0;
	smallest = s->arr[0];
	while (i < s->size)
	{
		if (smallest > s->arr[i])
			smallestindex = i;
		i++;
	}
	return (smallestindex);
}

void	pushsmallest(t_stack *s, int smallestindex)
{
	int	i;
	int	smallestindex;

	if (smallestindex > (s->size / 2))
		i = s->size - smallestindex;
	else
		i = smallestindex;
	while (i-- && smallestindex > (s->size / 2))
		s->revrotate(&s);
	while (i-- && smallestindex <= (s->size / 2))
		s->rotate(&s);
	s->push_to_other(&s, s->other);
}

void	sortfourfive(t_stack *s)
{
	int	smallestindex;
	int	i;

	i = s->size;
	while (s->size > 3)
	{
		smallestindex = find_smallest_index(s);
		pushsmallest(s, smallestindex);
	}
	sortthree(s);
	while (s->other->size > 0)
		s->push_to_self;
}

// void	sortfive(t_stack *s)
// {
// 	t_op	rt;
// 	t_op	revrt;
// 	t_op2	push;
// 	t_op2	pushb;
// 	t_op	r;

// 	if (s->name == 'a')
// 	{
// 		rt = ra;
// 		revrt = rra;
// 		push = pb;
// 		pushb = pa;
// 	}
// 	else
// 	{
// 		rt = rb;
// 		revrt = rrb;
// 		push = pa;
// 		pushb = pb;
// 	}
// 	if (rt_or_revrt() > 0)
// 		r = rt;
// 	else
// 		r = revrt;
// 	s5logic(s, push, pushb, r);
// }

// int	rt_or_revrt(t_stack *s)
// {
// 	int	num;
// 	// find out if the smallest is closer to top or bottom
// 	// if in middle or upper half, return +ve num of times to rotate it to top
// 	// if below middle, return
//	// -ve num. value should be num of times to rev rotate to top.
// 	return (num);
// }

// void	s5logic(t_stack *s, t_op2 push, t_op2 pushb, t_op r)
// {
// 	int	i;

// 	// find the smallest and push
// 	i = find_smallest(s);
// 	// find the 2nd smallest and push
// 	// sort three
// 	// push back 2nd smallest
// 	// push back
// }
