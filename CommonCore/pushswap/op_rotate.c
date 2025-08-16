/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:32:44 by rchiam            #+#    #+#             */
/*   Updated: 2025/08/15 21:44:28 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(t_stack *s)
{
	int	last;

	last = s->arr[s->size - 1];
	ft_memmove(s->arr + 1, s->arr, (s->size - 1) * sizeof(int));
	(s->arr)[0] = last;
}
void	ra(t_stack *a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}
void	rb(t_stack *b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}
void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}
/*
write(2, "Error\n", 6);
int		i = 1;

i <<= 1;

0x0F
0xF0
0000 1111
1111 0000

0000 0000
0000 0000 <- 0000 0011, 0000 0010, 0000 0001, 0000 0000

0x01	0000 0001
0x02	0000 0010
0x04	0000 0100
0x08	0000 1000

0x10	
0x20
0x40
0x80

500



*/