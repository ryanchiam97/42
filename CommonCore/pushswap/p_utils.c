/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 03:51:55 by user42            #+#    #+#             */
/*   Updated: 2025/09/06 17:07:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// int isqrt(int n)
// {
//     int x = n;
//     int y = (x + 1) / 2;

//     while (y < x)
//     {
//         x = y;
//         y = (x + n / x) / 2;
//     }
//     return x;
// }
// int imin(int a, int b)
// {
//     if (a < b)
//         return a;
//     return b;
// }
// int imax(int a, int b)
// {
//     if (a > b)
//         return a;
//     return b;
// }
// int ilog2(int n)
// {
//     int log = 0;

//     while (n > 1)
//     {
//         n = n / 2;
//         log++;
//     }
//     return log;
// }
// void    updateminmaxzero(t_stack *s)
// {
//     s->max = 0;
//     s->min = 0;
//     s->maxindex = -1;
//     s->minindex = -1;
// }

// void    updateminmax(t_stack *s)
// {
//     int i;
//     int min;
//     int max;

//     min = INT_MAX;
//     max = INT_MIN;
//     i = 0;
//     if (s->size == 0)
//         return (updateminmaxzero(s));
//     while (i < s->size)
//     {
//         if (s->arr[i] > max)
//         {
//             s->max = s->arr[i];
//             s->maxindex = i;
//         }
//         if (s->arr[i] < min)
//         {
//             s->min = s->arr[i];
//             s->minindex = i;
//         }
//         i++;
//     }
// }
