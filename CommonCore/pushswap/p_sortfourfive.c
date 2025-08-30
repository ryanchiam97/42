/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_sortfourfive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 22:35:23 by rchiam            #+#    #+#             */
/*   Updated: 2025/08/30 14:38:54 by rchiam           ###   ########.fr       */
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
	smallestindex = 0;
	while (i < s->size)
	{
		if (smallest >= s->arr[i])
		{
			smallestindex = i;
			smallest = s->arr[i];
		}
		i++;
	}
	return (smallestindex);
}

void	pushsmallest(t_stack *s, int smallestindex)
{
	int	i;

	if (smallestindex <= (s->size / 2))
		i = smallestindex;
	else
		i = -(s->size - smallestindex);
	while (i > 0)
	{
		s->rotate(s);
		i--;
	}
	while (i < 0)
	{
		s->revrotate(s);
		i++;
	}
	if (s->name == 'a')
		s->push_to_other(s, s->other);
	else
		s->push_to_other(s->other, s);
}

void	sortfourfive(t_stack *s)
{
	int	smallestindex;

	while (s->size > 3)
	{
		smallestindex = find_smallest_index(s);
		pushsmallest(s, smallestindex);
	}
	sortthree(s);
	while (s->other->size > 0)
	{
		if (s->name == 'a')
			s->push_to_self(s, s->other);
		else
			s->push_to_self(s->other, s);
	}
}

// to fix the smallest index. smallest one not being pushed over.
