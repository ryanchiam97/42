/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:34:54 by rchiam            #+#    #+#             */
/*   Updated: 2025/08/22 23:56:46 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	bitcheck(int bitinput, int tocheck, int power)
{
	if (bitinput == 1)
	{
		if ((tocheck & (0x01 << power)) == 1)
			return (1);
	}
	else
	{
		if ((tocheck ^ (0x01 << power)) == 1)
			return (1);
	}
	return (0);
}

int	determinerotation(t_stack *s, int bit, int power)
{
	int				rot;
	int				revrot;

	rot = 0;
	while (rot < s->size)
	{
		if (bitcheck(bit, s->arr[rot], power))
			break ;			// while (s->other->size!=0)
			// s->pushtoself

	{
		if (bitcheck(bit, s->arr[s->size - revrot], power))
			break ;
		else
			revrot++;
	}
	if (rot > revrot)
		return (rot);
	else
		return (revrot * -1);
}

int	*determinecheapestmacro(t_stack *s, int power, int *pushwho)
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

int	radixsort(t_stack *s, int totalbinarydigits)
{
	int	p;
	int	rotation;
	int	pushbit;

	p = 0;
	while (p < totalbinarydigits)
	{
		rotation = determinecheapestmacro(s, p, &pushbit);
		// pushover
		if (rotation > 0)
		{
			// while rotation > 0
				// if pushbit ^ (s->arr[0] >> p)
					// do rotate
				//else
					// do push over 
					// rotation--
		}
		else
		{
			//while rotation < 0
				// if pushbit ^ ( s->arr[0] >> p)
					// do revrotate
				//else
					// do push over
					// rotation++
		}
		//pushback
		// while (s->other->size!=0)
			//if pushbit == 0
				// s->pushtoself
			//else
				//s->pushtoself
				//s->rotate
		p++;
	}		
}

