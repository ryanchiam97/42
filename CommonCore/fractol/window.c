/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 21:30:00 by rchiam            #+#    #+#             */
/*   Updated: 2025/10/04 16:51:48 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_image(t_data *data)
{
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img.img_addr = mlx_get_data_addr(data->img.img_ptr,
											&data->img.bpp,
											&data->img.size_line,
											&data->img.endian);
}

void	pixel_to_image(t_data *data, int x, int y, int color)
{
	int	pixel_offset;
	int	bytes_per_pixel;

	bytes_per_pixel = data->img.bpp / 8;
	pixel_offset = (y * data->img.size_line) + (x * bytes_per_pixel);
	*(unsigned int *)(data->img.img_addr + pixel_offset) = color;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, &data->img, x, y);
}

void	defaultcamera(t_data *data)
{
	if (data->fractol.name == "Mandelbrot")
	{
		data->cam.re_min = -2.0;
		data->cam.re_max = 1.0;
		data->cam.im_min = -1.0;
		data->cam.im_max = 1.0;
	}
	if (data->fractol.name == "Julia")
	{
		data->cam.re_min = -2.0;
		data->cam.re_max = 2.0;
		data->cam.im_min = -1.5;
		data->cam.im_max = 1.5;
	}
}
