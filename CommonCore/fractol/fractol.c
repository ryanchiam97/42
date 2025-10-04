/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:43:21 by rchiam            #+#    #+#             */
/*   Updated: 2025/09/30 23:46:29 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// mandelbrot
// z_n+1 	= z^2_n + c
// 			= (zx + zyi)^2 + (x + y)
// 			= (zx * zx + 2zxzyi - zy * zy) + cx + cy
//			= (zx*zx + cx + cy - zy * zy)x + (2 * zx * zy)y
// z_0 = 0 + 0i
// c = pixel coords
int	get_fractol_color(int x, int y)
{
	t_z	zn;
	t_z	ztemp;
	int	count;

	count = 0;
	zn.x = 0;
	zn.y = 0;
	while (count < MAX_ITERATIONS || (zn.x * zn.x) + (zn.y * zn.y) > 4)
	{
		ztemp.x = zn.x * zn.x + x + y - (zn.y * zn.y);
		ztemp.y = 2 * zn.x * zn.y;
		zn.x = ztemp.x;
		zn.y = ztemp.y;
		count++;
	}
	if (count >= MAX_ITERATIONS)
		return (0x000000);
	return ((count * 0x123456) % 0xFFFFFF);
}

// julia
// z_n+1 = z^2_n + c
// z_0 = pixel coords
// c = input complex number

// for both,
// count the number of iterations
// until
// |z_n| > 2
// or
// x^2 + y^2 > 4 (equivlent)
// colour the pixel according to the iterations
// if count = MAX_ITERATION (eg 100), set as black

//mlx slides
//https://www.canva.com/design/DAGT6G8aJHY/fqork5u1hxZONk8a4WQtdQ/view
