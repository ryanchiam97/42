/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:33:15 by rchiam            #+#    #+#             */
/*   Updated: 2025/08/15 21:19:31 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pushswap.h"
void	revrotate(t_stack *s)
{
	int first;

	first = s->arr[0];
	ft_memmove(s->arr, s->arr + 1, (s->size - 1) * sizeof(int));
	(s->arr)[s->size - 1] = first;
}
void rra(t_stack *a)
{
	revrotate(a);
	ft_putstr_fd("rra\n", 1);
}
void rrb(t_stack *b)
{
	revrotate(b);
	ft_putstr_fd("rrb\n", 1);
}
void rrr(t_stack *a, t_stack *b)
{
	revrotate(a);
	revrotate(b);
	ft_putstr_fd("rrr\n", 1);
}
