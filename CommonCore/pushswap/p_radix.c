/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_radix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:34:54 by rchiam            #+#    #+#             */
/*   Updated: 2025/08/30 22:47:37 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	determinerotation(t_stack *s, int bit, int power)
{
	int				rr;
	int				r;

	rr = 0;
	while (rr < s->size)
	{
		if (bit ^ ((s->arr[rr] >> power) & 1))
			break ;
		else
			rr++;
	}
	rr = s->size - rr + 1;
	r = 0;
	while (r < s->size)
	{
		if (bit ^ ((s->arr[s->size - r] >> power) & 1))
			break ;
		else
			r++;
	}
	r = s->size - r;
	if (rr > r)
		return ((rr) * -1);
	else
		return (r);
}

int	cheapest_order(t_stack *s, int power, int *pushwho)
{
	int	ops0;
	int	ops1;
	int	r0;
	int	r1;

	r0 = determinerotation(s, 0, power);
	r1 = determinerotation(s, 1, power);
	ops0 = (2 * abs(r0));
	ops1 = (3 * abs(r1));
	if (ops1 < ops0)
	{
		*pushwho = 1;
		return (r1);
	}
	else
	{
		*pushwho = 0;
		return (r0);
	}
}

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

void	pushback(t_stack *s, int pushbit)
{
	while (s->other->size > 0)
	{
		if (s->name == 'a')
			s->push_to_self(s, s->other);
		else
			s->push_to_self(s->other, s);
		if (pushbit == 1)
			s->revrotate(s);
	}
}

void	radixsort(t_stack *s, int totalbinarydigits)
{
	int	p;
	// int	rotation;
	// int	pushbit;
	int	i;

	p = 0;
	while (p < totalbinarydigits)
	{
		// rotation = cheapest_order(s, p, &pushbit);
		// pushover(s, pushbit, rotation, p);
		i = s->size;
		while (i-- > 0)
		{
			if (((s->arr[0] >> p) & 1) == 0)
				s->push_to_other(s, s->other);
			else
				s->rotate(s);
		}
		// pushback(s, pushbit);
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
