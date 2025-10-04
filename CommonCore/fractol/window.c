/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 21:30:00 by rchiam            #+#    #+#             */
/*   Updated: 2025/09/30 21:37:24 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_close(t_var *data)
{
	if (data)
	{
		if (data->win_ptr)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		if (data->mlx_ptr)
		{
			mlx_destroy_display(data->mlx_ptr);
			free(data->mlx_ptr);
		}
	}
	exit(0);
	return (0);
}

int	ft_keypress(int keycode, t_var *data)
{
	if (keycode == 65307)
		ft_close(data);
	return (0);
}

void	init_image(t_var *data)
{
	data->img.ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.ptr,
										&data->img.bpp,
										&data->img.size_line,
										&data->img.endian);
}

void	pixel_to_image(t_var *data, int x, int y, int color)
{
	int	pixel_offset;
	int	bytes_per_pixel;

	bytes_per_pixel = data->img.bpp / 8;
	pixel_offset = (y * data->img.size_line) + (x * bytes_per_pixel);
	*(unsigned int *)(data->img.addr + pixel_offset) = color;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, &data->img, x, y);
}

