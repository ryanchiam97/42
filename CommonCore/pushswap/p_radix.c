/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_radix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:34:54 by rchiam            #+#    #+#             */
/*   Updated: 2025/09/04 04:26:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pushover(t_stack *s, int pushbit, int rot, int power)
{
	int	final;

	final = 0;
	while (rot != 0 || final == 1)
	{
		if (pushbit ^ ((s->arr[0] >> power) & 1))
		{
			if (rot > 0)
				s->rotate(s);
			else if (rot < 0)
				s->revrotate(s);
		}
		else
			s->push_to_other(s, s->other);
		if (rot > 0)
			rot--;
		if (rot < 0)
			rot++;
		if (rot == 0)
			final++;
	}
	return ;
}

void	pushback(t_stack *s)
{
	while (s->other->size > 0)
	{
		s->push_to_self(s, s->other);
	}
}

int	determinechunksize(t_stack *s, double alpha, int nmin, int nmax)
{
	double	raw;

	if (s->size < nmin)
		return (0);
	else
	{
		raw = alpha * (double)isqrt(s->size) * (double)ilog2(s->size);
		return ((int)imin(imax((int)raw, nmin), nmax));
	}
}

int	onechunk(t_stack* s, int mincborder, int maxcborder)
{
	int	i;
	int	count;
	int	p;
	int	r;

	i = 0;
	count = maxcborder - mincborder;
	while(i < s->size || i < count)
	{
		if (s->arr[i] >= mincborder && s->arr[i] <= maxcborder)
		{
			s->push_to_other(s, s->other);
			p++;
		}
		else
		{
			s->rotate(s);
			r++;
		}
		i++;
	}
	return (r / p);
}

void	chunkdecisionlayer(t_stack *s, int r_per_p_threshold, int CincreFractnOfRemain)
{
	int	chunksize;
	int	minCborder;
	int	maxCborder;
	int	rot_per_push;

	//chunksize = determinechunksize(s, 0.3, 12, s->size / 5);
	chunksize = 50;
	minCborder = 0;
	maxCborder = chunksize;
	while (maxCborder < s->size)
	{
		rot_per_push = onechunk(s, minCborder, maxCborder);
		pushback(s);
		if (rot_per_push > r_per_p_threshold)
			chunksize+=((s->size - maxCborder) / CincreFractnOfRemain);
		minCborder = maxCborder + 1;
		maxCborder = imin((minCborder + chunksize), s->size);
	}
	return (globalradixsort(s, determinepower(s->size - 1)));
}
//get size of chunk and range
// rotate and push over if in range
// do minichunk radix
// repeat

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
}

void printout_stack_info(t_stack *s)
{
	int ilim = s->size;
	int jlim = s->other->size;
	int i = 0;
	int j = 0;
	printf("stack %c: ", s->name);
	while (i < ilim)
	{
		printf("%i ", s->arr[i]);
		i++;
	}
	printf("\t");
	printf("stack %c: ", s->other->name);
	while (j < jlim)
	{
		printf("%i ", s->other->arr[j]);
		j++;
	}
	printf("\n");
}

