/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:43:21 by rchiam            #+#    #+#             */
/*   Updated: 2025/10/10 15:49:40 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	alldigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) || (str[i] == '.' && str[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

// mandelbrot / julia equation
// z_n+1 	= z^2_n + c
// 			= (zx + zyi)^2 + (x + y)
// 			= (zx * zx + 2zxzyi - zy * zy) + cx + cy
//			= (zx*zx + cx + cy - zy * zy)x + (2 * zx * zy)y
// mandelbrot
// z_0 = 0 + 0i
// c = pixel coords
// julia
// z_0 = pixelcoords
// c = constant from input

int	mandelbrot_count(double re, double im)
{
	return (get_fractol_count(0, 0, re, im));
}

int	julia_count(double re, double im, t_data *data)
{
	t_z	c;

	c.re = data->f.z.re;
	c.im = data->f.z.im;
	return (get_fractol_count(re, im, c.re, c.im));
}

int	get_fractol_count(double zx, double zy, double cx, double cy)
{
	int		count;
	double	tmp_x;
	double	tmp_y;

	count = 0;
	while (zx * zx + zy * zy <= 4 && count < MAX_ITERATIONS)
	{
		tmp_x = zx * zx - zy * zy + cx;
		tmp_y = 2 * zx * zy + cy;
		zx = tmp_x;
		zy = tmp_y;
		count++;
	}
	return (count);
}

int	count_to_color(int count, int color_shift, int mx_iter)
{
	if (count >= MAX_ITERATIONS || count >= mx_iter)
		return (0x000000);
	return ((count * 0x123456 + color_shift) % 0xFFFFFF);
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
