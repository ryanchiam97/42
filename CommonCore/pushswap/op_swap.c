/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:30:11 by rchiam            #+#    #+#             */
/*   Updated: 2025/08/14 22:15:19 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
int	swap(t_stack *s)
{
	int	tmp;

	if (s->size < 2)
		return (0);
	tmp = s->arr[0];
	s->arr[0] = s->arr[1];
	s->arr[1] = tmp;
	return (1);
}
void sa(t_stack *a)
{
	if (swap(a))
		ft_putstr_fd("sa\n", 1);
}
void sb(t_stack *b)
{
	if (swap(b))
		ft_putstr_fd("sb\n", 1);
}
void ss(t_stack *a, t_stack *b)
{
	int	_sa;
	int	_sb;
	_sa = swap(a);
	_sb = swap(b);
	if (_sa && _sb)
		ft_putstr_fd("ss", 1);
	else if (_sa == 1 && _sb == 0)
		sa(a);
	else if (_sa == 0 && _sb == 1)
		sb(b);
}