/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_radix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:34:54 by rchiam            #+#    #+#             */
/*   Updated: 2025/09/19 20:36:17 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// int	pushback(t_stack *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s->other->size > 0)
// 	{
// 		s->push_to_self(s, s->other);
// 		i++;
// 	}
// 	return (i);
// }

// int	getchunksize(t_stack *s)
// {
// 	int	chunksize;

// 	chunksize = isqrt(s->size);
// 	if (chunksize > 64)
// 		return (64);
// 	return (chunksize); 
// }
// void	sortchunk(t_stack *s)
// {
// 	if (s->size <= 3)
// 		sortthree(s);
// 	else if (s->size <= 5)
// 		sortfourfive(s);
// 	else
// 		globalradixsort(s, determinepower(s->size - 1));
// }

// void	sendoverchunk(t_stack *s, int start, int end)
// {
// 	int	pos;
// 	int	chunksize;

// 	chunksize = end - start + 1;
// 	while (chunksize > 0)
// 	{
// 		pos = 0;
// 		while (!(s->arr[pos] >= start && s->arr[pos] <= end))
// 			pos++;
// 		if (pos <= s->size / 2)
// 			while (pos--)
// 				s->rotate(s);
// 		else
// 			while (pos++ < s->size)
// 				s->revrotate(s);
// 		if (chunksize > 5)
// 			smartpush(s, s->other);
// 		else
// 			s->push_to_other(s, s->other);
// 		chunksize--;
// 	}
// 	if (end - start + 1 <= 5)
// 		sortfourfive (s->other);
// }

// void	handlemiddlecase(t_stack *b, int aVal)
// {
// 	int	smallestbiggerval;
// 	int	smallestbiggerindex;
// 	int	i;

// 	smallestbiggerval = b->max;
// 	i = 0;
// 	while (i < b->size)
// 	{
// 		if (b->arr[i] > aVal && b->arr[i] < smallestbiggerval)
// 		{
// 			smallestbiggerval = b->arr[i];
// 			smallestbiggerindex = i;
// 		}
// 		i++;
// 	}
// 	while (b->arr[0] != smallestbiggerval)
// 	{
// 		if (smallestbiggerindex <= b->size /2)
// 			b->rotate(b);
// 		else
// 			b->revrotate(b);
// 	}
// 	b->other->push_to_other(b->other, b);
// }

// void	smartpush(t_stack *a, t_stack *b)
// {
// 	int	aVal;
// 	int	smallestbiggernum;
// 	int	i;

// 	aVal = a->arr[0];
// 	if (b->size <= 1)
// 		return (a->push_to_other(a, b));
// 	if (aVal < b->min || aVal > b->max)
// 	{
// 		while (b->minindex !=0)
// 		{
// 			if (b->minindex <= b->size/2)
// 				b->rotate(b);
// 			else
// 				b->revrotate(b);
// 		}
// 		a->push_to_other(a, b);
// 	}
// 	else
// 		handlemiddlecase(b, aVal);
// }

// void	chunkdecisionlayer(t_stack *s)
// {
// 	int	chunksize;
// 	int	chunkremaining;
// 	int	chunkstart;
// 	int	chunkend;
// 	int	pushedback;

// 	chunksize = getchunksize(s);
// 	chunkremaining = (s->size + chunksize - 1) / chunksize;
// 	chunkstart = 0;
// 	chunkend = chunksize;
// 	while (chunkremaining--)
// 	{
// 		//scan through and send over any in range(optimized)
// 		sendoverchunk(s, chunkstart, chunkend);
// 		pushedback = pushback(s);
// 		chunkstart = chunkend + 1;
// 		chunkend = chunkstart + chunksize;
// 		if (chunkend >= s->size)
// 			chunkend = s->size - 1;
// 		while (pushedback--)
// 			s->rotate(s);
// 	}
// 	return (globalradixsort(s, determinepower(s->size - 1)));
// }

// void printout_stack_info(t_stack *s)
// {
// 	int ilim = s->size;
// 	int jlim = s->other->size;
// 	int i = 0;
// 	int j = 0;
// 	printf("stack %c: ", s->name);
// 	while (i < ilim)
// 	{
// 		printf("%i ", s->arr[i]);
// 		i++;
// 	}
// 	printf("\t");
// 	printf("stack %c: ", s->other->name);
// 	while (j < jlim)
// 	{
// 		printf("%i ", s->other->arr[j]);
// 		j++;
// 	}
// 	printf("\n");
// }

void	globalradixsort(t_stack *s, int totalbinarydigits)
{
	int	p;
	int	i;

	p = 0;
	while (p < totalbinarydigits)
	{
		i = s->size;
		while (i-- > 0)
		{
			if (((s->arr[0] >> p) & 1) == 0)
				s->push_to_other(s, s->other);
			else
				s->rotate(s);
		}
		while (s->other->size > 0)
			s->push_to_self(s, s->other);
		p++;
	}
	while (s->arr[0] != 1)
		s->rotate(s);
}
