/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:29:45 by rchiam            #+#    #+#             */
/*   Updated: 2025/08/23 17:04:13 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	push(t_stack *src, t_stack *dst)
{
	int	pushnum;

	if (src->size == 0)
		return (0);
	pushnum = src->arr[0];
	ft_memmove(src->arr, src->arr + 1, (src->size - 1) * sizeof(int));
	ft_memmove(dst->arr + 1, dst->arr, (dst->size) * sizeof(int));
	dst->arr[0] = pushnum;
	src->size--;
	dst->size++;
	return (1);
}

void	pa(t_stack *a, t_stack *b)
{
	if (push(a, b))
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *b, t_stack *a)
{
	if (push(b, a))
		ft_putstr_fd("pb\n", 1);
}
