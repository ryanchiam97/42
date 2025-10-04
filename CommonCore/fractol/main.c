/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:50:44 by rchiam            #+#    #+#             */
/*   Updated: 2025/10/04 16:55:09 by rchiam           ###   ########.fr       */
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
		ft_close(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
//Remember to add in your own printf in here. 
//Replace all the printf with ft_printf
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
	mlx_hook(data.win_ptr, 17, 1 << 17, &ft_close, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &ft_keypress, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

// fractal type
// fractal zoom coords in imaginary img + limits
// iter and colors