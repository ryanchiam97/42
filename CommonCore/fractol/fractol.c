/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:43:21 by rchiam            #+#    #+#             */
/*   Updated: 2025/10/04 17:27:06 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	determinefractol(int argc, char **argv, t_data *data)
{
	int	error;

	if (argv[1] == "Manderbrot" && argc == 2)
		data->fractol.name = argv[1];
	else if (argv[1] == "Julia" && argc == 4
		&& ft_isdigit(argv[2]) && ft_isdigit(argv[3]))
	{
		data->fractol.name = argv[1];
		data->fractol.input.x = ft_atoi(argv[2]);
		data->fractol.input.y = ft_atoi(argv[3]);
	}
	else
		error = 1;
	if (error == 1)
	{
		printf("Input Error\n");
		printf("****************************************************\n");
		printf("*Only Accepted Inputs:                             *\n");
		printf("*./fractol Mandelbrot                              *\n");
		printf("*./fractol Julia X(int) Y(int)                     *\n");
		printf("****************************************************\n");
		return (0);
	}
	return (1);
}

// mandelbrot
// z_n+1 	= z^2_n + c
// 			= (zx + zyi)^2 + (x + y)
// 			= (zx * zx + 2zxzyi - zy * zy) + cx + cy
//			= (zx*zx + cx + cy - zy * zy)x + (2 * zx * zy)y
// z_0 = 0 + 0i
// c = pixel coords
int	fractol(t_data *data)
{
	if (data->fractol.name == "Mandelbrot")
		// do get_fractol_count
	else if (data->fractol.name == "Julia")
		//
	//mandelbrot: fractal_iter((0,0), (re,im), MAX_ITERATIONS)
	//julia: fractal_iter((re,im), (cx,cy), MAX_ITERATIONS)
}

int	get_fractol_count(int x, int y)
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
	return (count);
}

int	count_to_color(int count, int color_shift, int max_iter)
{
	if (count >= MAX_ITERATIONS || count >= max_iter)
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
