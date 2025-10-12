/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 21:30:00 by rchiam            #+#    #+#             */
/*   Updated: 2025/10/12 15:51:54 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_image(t_data *data)
{
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img.img_addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
			&data->img.size_line, &data->img.endian);
}

void	defaultcamera(t_data *data)
{
	if (ft_strncmp(data->f.name, "Mandelbrot", 10) == 0)
	{
		data->cam.re_min = -2.5;
		data->cam.re_max = 1.0;
		data->cam.im_min = -1.2;
		data->cam.im_max = 1.2;
	}
	if (ft_strncmp(data->f.name, "Julia", 5) == 0)
	{
		data->cam.re_min = -2.0;
		data->cam.re_max = 2.0;
		data->cam.im_min = -1.5;
		data->cam.im_max = 1.5;
	}
	if (ft_strncmp(data->f.name, "BurningShip", 12) == 0)
	{
		data->cam.re_min = -2.1;
		data->cam.re_max = 1.3;
		data->cam.im_min = -2.0;
		data->cam.im_max = 2.2;
	}
	data->cam.c_shift = COLORJUMP;
	data->cam.mx_iter = MAX_ITERATIONS;
}

int	ft_keypress(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		ft_close(data);
		return (0);
	}
	else if (keycode == 65361)
		pan(data, -1 * PANSPEED, 0);
	else if (keycode == 65363)
		pan(data, PANSPEED, 0);
	else if (keycode == 65362)
		pan(data, 0, PANSPEED);
	else if (keycode == 65364)
		pan(data, 0, -1 * PANSPEED);
	else if (keycode == 32)
		defaultcamera(data);
	else if (keycode == 65505 || keycode == 65506)
		colorshift(data);
	render(data);
	return (0);
}

int	ft_mousehook(int button, int x, int y, t_data *data)
{
	if (button == 4)
		zoom(data, x, y, 1.1);
	else if (button == 5)
		zoom(data, x, y, 0.9);
	render(data);
	return (0);
}

void	instructions(void)
{
	ft_printf("****************************************************\n");
	ft_printf("*Accepted Inputs:                                  *\n");
	ft_printf("*        ./fractol Mandelbrot                      *\n");
	ft_printf("* OR     ./fractol Julia X.f Y.f                   *\n");
	ft_printf("* OR     ./fractol BurningShip                     *\n");
	ft_printf("****************************************************\n");
}