/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_sortfourfive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 22:35:23 by rchiam            #+#    #+#             */
/*   Updated: 2025/08/23 17:26:51 by rchiam           ###   ########.fr       */
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
		s->revrotate(s);
	while (i-- && smallestindex <= (s->size / 2))
		s->rotate(s);
	s->push_to_other(s, s->other);
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
		s->push_to_self(s->other, s);
}
