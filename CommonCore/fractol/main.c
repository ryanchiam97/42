/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:50:44 by rchiam            #+#    #+#             */
/*   Updated: 2025/10/10 03:28:32 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(t_data *data)
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

int	ft_keypress(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		ft_close(data);
		return (0);
	}
	else if (keycode == 65361)//left
		pan(data, -0.001, 0);
	else if (keycode == 65363)//right
		pan(data, 0.001, 0);
	else if (keycode == 65362)//up
		pan(data, 0, 0.001);
	else if (keycode == 65364)//down
		pan(data, 0, -0.001);
	else if (keycode == 32)
		defaultcamera(data);
	render(data);
	return (0);
}

int	ft_mousehook(int button, int x, int y, t_data *data)
{
	if (button == 4)//zoom in
		zoom(data, x, y, 1.1);
	else if (button == 5)//zoom out
		zoom(data, x, y, 0.9);
	render(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
//Remember to add in your own printf in here. 
//Replace all the printf with ft_printf
	if (argc < 2)
		return (printf("Error\n no arg"), 1);
	if (!determinefractol(argc, argv, &data))
		return (printf("Error\n"), 1);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "window");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	init_image(&data);
	defaultcamera(&data);
	render(&data);
	mlx_mouse_hook(data.win_ptr, &ft_mousehook, &data);
	mlx_hook(data.win_ptr, 17, 0, &ft_close, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &ft_keypress, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

// fractal type
// fractal zoom coords in imaginary img + limits
// iter and colors