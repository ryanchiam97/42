/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_sortfourfive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 22:35:23 by rchiam            #+#    #+#             */
/*   Updated: 2025/09/06 17:06:04 by user42           ###   ########.fr       */
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

	if (s->size <= 3)
		sortthree(s);
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

// int	find_largest_index(t_stack *s)
// {
// 	int	i;
// 	int	largest;
// 	int	largestindex;

// 	i = 0;
// 	largest = s->arr[0];
// 	largestindex = 0;
// 	while (i < s->size)
// 	{
// 		if (largest <= s->arr[i])
// 		{
// 			largestindex = i;
// 			largest = s->arr[i];
// 		}
// 		i++;
// 	}
// 	return (largestindex);
// }

// void	pushlargest(t_stack *s, int largestindex)
// {
// 	int	i;

// 	if (largestindex <= (s->size / 2))
// 		i = largestindex;
// 	else
// 		i = -(s->size - largestindex);
// 	while (i > 0)
// 	{
// 		s->rotate(s);
// 		i--;
// 	}
// 	while (i < 0)
// 	{
// 		s->revrotate(s);
// 		i++;
// 	}
// 	if (s->name == 'a')
// 		s->push_to_other(s, s->other);
// 	else
// 		s->push_to_other(s->other, s);
// }

// void	sortrfourfive(t_stack *s)
// {
// 	int	largestindex;

// 	if (s->size <= 3)
// 		sortrthree(s);
// 	while (s->size > 3)
// 	{
// 		largestindex = find_largest_index(s);
// 		pushlargest(s, largestindex);
// 	}
// 	sortrthree(s);
// 	while (s->other->size > 0)
// 	{
// 		if (s->name == 'a')
// 			s->push_to_self(s, s->other);
// 		else
// 			s->push_to_self(s->other, s);
// 	}
// }