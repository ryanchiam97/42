/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_sortthree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:37:39 by rchiam            #+#    #+#             */
/*   Updated: 2025/08/16 16:21:00 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sortthree(t_stack *s)
{
	if (s->arr[0] < s->arr[1] && s->arr[1] < s->arr[2])
		return ;
	else if (s->arr[1] < s->arr[0] && s->arr[0] < s->arr[2])
		return (s->swap(&s));
	else if (s->arr[2] < s->arr[0] && s->arr[0] < s->arr[1])
		return (s->revrotate(&s));
	else if (s->arr[1] < s->arr[2] && s->arr[2] < s->arr[0])
		return (s->rotate(&s));
	else if (s->arr[2] < s->arr[1] && s->arr[1] < s->arr[0])
		return (s->rotate(&s), s->swap(&s));
	else if (s->arr[0] < s->arr[2] && s->arr[2] < s->arr[1])
		return (s->revrotate(&s), s->swap(&s));
}

// void	sortthree(t_stack *s)
// {
// 	t_op	swp;
// 	t_op	rt;
// 	t_op	revrt;

// 	if (s->name == 'a')
// 	{
// 		swp = sa;
// 		rt = ra;
// 		revrt = rra;
// 	}
// 	else
// 	{
// 		swp = sb;
// 		rt = rb;
// 		revrt = rrb;
// 	}
// 	sortthreelogic(s, swp, rt, revrt);
// }

// void	sortthreelogic(t_stack *s, t_op swp, t_op rt, t_op revrt)
// {
// 	if (s->arr[0] < s->arr[1] && s->arr[1] < s->arr[2])
// 		return ;
// 	else if (s->arr[1] < s->arr[0] && s->arr[0] < s->arr[2])
// 		return (swp(s));
// 	else if (s->arr[2] < s->arr[0] && s->arr[0] < s->arr[1])
// 		return (revrt(s));
// 	else if (s->arr[1] < s->arr[2] && s->arr[2] < s->arr[0])
// 		return (rt(s));
// 	else if (s->arr[2] < s->arr[1] && s->arr[1] < s->arr[0])
// 		return (rt(s), swp(s));
// 	else if (s->arr[0] < s->arr[2] && s->arr[2] < s->arr[1])
// 		return (revrt(s), swp(s));
// }
