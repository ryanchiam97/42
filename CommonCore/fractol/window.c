/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 21:30:00 by rchiam            #+#    #+#             */
/*   Updated: 2025/10/10 02:52:17 by rchiam           ###   ########.fr       */
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

void	defaultcamera(t_data *data)
{
	if (ft_strncmp(data->fractol.name, "Mandelbrot", 10) == 0)
	{
		data->cam.re_min = -2.0;
		data->cam.re_max = 2.0;
		data->cam.im_min = -1.5;
		data->cam.im_max = 1.5;
	}
	if (ft_strncmp(data->fractol.name, "Julia", 5) == 0)
	{
		data->cam.re_min = -2.0;
		data->cam.re_max = 2.0;
		data->cam.im_min = -1.5;
		data->cam.im_max = 1.5;
	}
	data->cam.c_shift = 1;
	data->cam.mx_iter = MAX_ITERATIONS;
}

