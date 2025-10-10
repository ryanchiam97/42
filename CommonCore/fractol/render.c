/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 21:36:44 by rchiam            #+#    #+#             */
/*   Updated: 2025/10/10 15:49:01 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render(t_data *data)
{
	int	x;
	int	y;
	int	color;
	int	count;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (ft_strncmp("Mandelbrot", data->f.name, 10) == 0)
				count = mandelbrot_count(map_x(data, x), map_y(data, y));
			else if (ft_strncmp("Julia", data->f.name, 5) == 0)
				count = julia_count(map_x(data, x), map_y(data, y), data);
			color = count_to_color(count, data->cam.c_shift, data->cam.mx_iter);
			color_pixel(&data->img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
}

void	color_pixel(t_img *img, double re, double im, int color)
{
	char	*dst;

	dst = img->img_addr + (int)(im * img->size_line + re * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

double	map_x(t_data *data, int x)
{
	double	min;
	double	max;

	min = data->cam.re_min;
	max = data->cam.re_max;
	return (min + (double)x * (max - min) / (double)(WIDTH));
}

double	map_y(t_data *data, int y)
{
	double	min;
	double	max;

	min = data->cam.im_min;
	max = data->cam.im_max;
	return (max - y * (max - min) / (double)(HEIGHT));
}
