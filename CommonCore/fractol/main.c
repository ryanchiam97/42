/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:50:44 by rchiam            #+#    #+#             */
/*   Updated: 2025/09/30 00:36:32 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx_linux/mlx.h"

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

void	color_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	render(t_var *data)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = get_fractal_color(x, y, data);
			color_pixel(&data->img, x, y, color);
			x++;
		}
		y++;
	}
}

int	main(void)
{
	t_var	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "window");
	if (!data.win_ptr)
	{
		free(data.mlx_ptr);
		return (1);
	}
	init_image(&data);
	mlx_hook(data.win_ptr, 17, 1 << 17, &ft_close, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &ft_keypress, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
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
get_fractal_color()
// fractal type
// fractal zoom coords in imaginary img + limits
// iter and colors