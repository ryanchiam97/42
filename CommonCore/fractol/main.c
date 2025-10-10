/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:50:44 by rchiam            #+#    #+#             */
/*   Updated: 2025/10/10 16:32:12 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	instructions(void)
{
	ft_printf("****************************************************\n");
	ft_printf("*Accepted Inputs:                                  *\n");
	ft_printf("*        ./fractol Mandelbrot                      *\n");
	ft_printf("* OR     ./fractol Julia X Y                       *\n");
	ft_printf("* OR     ./BurningShip                             *\n");
	ft_printf("****************************************************\n");
	// need to make burning ship
	//	=> Add the flags for 
	// need to fix the atof in the libft
}

int	determinefractol(int argc, char **argv, t_data *data)
{
	int	error;

	error = 0;
	if (argc < 2)
		error = 1;
	if (error == 0 && ft_strncmp(argv[1], "Mandelbrot", 10) == 0 && argc == 2)
		data->f.name = argv[1];
	else if (error == 0 && ft_strncmp(argv[1], "Julia", 5) == 0 && argc == 4)
	{
		data->f.name = argv[1];
		data->f.z.re = ft_atoi(argv[2]);
		data->f.z.im = ft_atoi(argv[3]);
	}
	else
		error = 1;
	if (error == 1)
		return (instructions(), 0);
	return (1);
}

int	ft_close(t_data *data)
{
	if (data)
		mlx_loop_end(data->mlx_ptr);
	return (0);
}

int	cleanup(t_data *data)
{
	if (data->win_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (data->img.img_ptr && data->mlx_ptr)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
		data->img.img_ptr = NULL;
	}
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		data->mlx_ptr = NULL;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (determinefractol(argc, argv, &data))
	{
		data.mlx_ptr = mlx_init();
		if (!data.mlx_ptr)
			return (1);
		data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "window");
		if (!data.win_ptr)
			return (ft_close(&data));
		init_image(&data);
		defaultcamera(&data);
		render(&data);
		mlx_mouse_hook(data.win_ptr, &ft_mousehook, &data);
		mlx_hook(data.win_ptr, 17, 0, &ft_close, &data);
		mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &ft_keypress, &data);
		mlx_loop(data.mlx_ptr);
		cleanup(&data);
	}
	return (0);
}
