/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:50:44 by rchiam            #+#    #+#             */
/*   Updated: 2025/10/12 15:12:57 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handlejulia(t_data *data, char *name, char *str1, char *str2)
{
	int	valid;

	valid = 0;
	data->f.name = name;
	data->f.z.re = ft_atof(str1, &valid);
	if (valid == 0)
		return (0);
	data->f.z.im = ft_atof(str2, &valid);
	if (valid == 0)
		return (0);
	return (1);
}

int determinefractol(int argc, char **argv, t_data *data)
{
	int	err;

	err = 0;
	if (argc < 2)
		err = 1;
	if (err == 0)
	{
		if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0 && argc == 2)
			data->f.name = argv[1];
		else if (ft_strncmp(argv[1], "Julia", 5) == 0 && argc == 4) 
		{
			if (!handlejulia(data, argv[1], argv[2], argv[3]))
				err = 1;
			printf("re is %f, im is %f\n", data->f.z.re, data->f.z.im);
		}
		else if (ft_strncmp(argv[1], "BurningShip", 10) == 0 && argc == 2)
			data->f.name = argv[1];
		else
			err = 1;
	}
	if (err == 1)
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
