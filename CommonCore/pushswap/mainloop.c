/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:34:54 by rchiam            #+#    #+#             */
/*   Updated: 2025/08/23 17:25:35 by rchiam           ###   ########.fr       */
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
		if (bit ^ (s->arr[rr] >> power))
			break ;
		else
			rr++;
	}
	rr = s->size - rr;
	while (r < s->size)
	{
		if (bit ^ (s->arr[s->size - r] >> power))
			break ;
		else
			r++;
	}
	r = s->size - r;
	if (rr > r)
		return (rr * -1);
	else
		return (r);
}

int	calc_cheapest_order(t_stack *s, int power, int *pushwho)
{
	int	ops0;
	int	ops1;
	int	r0;
	int	r1;

	r0 = determinerotation(s, 0, power);
	r1 = determinerotation(s, 1, power);
	ops0 += (2 * abs(r0));
	ops1 += (3 * abs(r1));
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
	while (rot)
	{
		if (pushbit ^ (s->arr[0] >> power))
			s->rotate(s);
		else
			s->push_to_other(s, s->other);
		if (rot > 0)
			rot--;
		else
			rot++;
	}
	return ;
}

void	pushback(t_stack *s, int pushbit)
{
	while (s->other->size > 0)
	{
		s->push_to_self(s->other, s);
		if (pushbit == 1)
			s->rotate(s);
	}
}

int	radixsort(t_stack *s, int totalbinarydigits)
{
	int	p;
	int	rotation;
	int	pushbit;

	p = 0;
	while (p < totalbinarydigits)
	{
		rotation = calc_cheapest_order(s, p, &pushbit);
		pushover(s, pushbit, rotation, p);
		pushback(s, pushbit);
		p++;
	}
}
