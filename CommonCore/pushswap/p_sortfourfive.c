/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_sortfourfive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 22:35:23 by rchiam            #+#    #+#             */
/*   Updated: 2025/08/24 00:11:02 by rchiam           ###   ########.fr       */
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

	if (smallestindex > (s->size / 2))
		i = s->size - smallestindex;
	else
		i = smallestindex;
	while (i-- && smallestindex > (s->size / 2))
		s->revrotate(s);
	while (i-- && smallestindex <= (s->size / 2))
		s->rotate(s);
	s->push_to_other(s, s->other);
}

void	sortfourfive(t_stack *s)
{
	int	smallestindex;
	printf("A: a: %i\n%i\n%i\n%i\nb: %i\n%i\n%i\n%i\n", s->arr[0], s->arr[1],s->arr[2], s->arr[3], s->other->arr[0], s->other->arr[1],s->other->arr[2], s->other->arr[3]);
	while (s->size > 3)
	{
		smallestindex = find_smallest_index(s);
		printf("smallestindex: %i\n", smallestindex);
		pushsmallest(s, smallestindex);
		printf("B: a: %i\n%i\n%i\n%i\nb: %i\n%i\n%i\n%i\n", s->arr[0], s->arr[1],s->arr[2], s->arr[3], s->other->arr[0], s->other->arr[1],s->other->arr[2], s->other->arr[3]);
	}
	printf("C: a: %i\n%i\n%i\n%i\nb: %i\n%i\n%i\n%i\n", s->arr[0], s->arr[1],s->arr[2], s->arr[3], s->other->arr[0], s->other->arr[1],s->other->arr[2], s->other->arr[3]);
	sortthree(s);
	printf("D: a: %i\n%i\n%i\n%i\nb: %i\n%i\n%i\n%i\n", s->arr[0], s->arr[1],s->arr[2], s->arr[3], s->other->arr[0], s->other->arr[1],s->other->arr[2], s->other->arr[3]);
	while (s->other->size > 0)
		s->push_to_self(s->other, s);
	printf("E: a: %i\n%i\n%i\n%i\nb: %i\n%i\n%i\n%i\n", s->arr[0], s->arr[1],s->arr[2], s->arr[3], s->other->arr[0], s->other->arr[1],s->other->arr[2], s->other->arr[3]);
}

// to fix the smallest index. smallest one not being pushed over.
