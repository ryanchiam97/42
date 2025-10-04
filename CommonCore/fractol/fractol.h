/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:43:08 by rchiam            #+#    #+#             */
/*   Updated: 2025/10/04 16:46:41 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx_linux/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <X11/X.h>
# include <X11/keysymdef.h>

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITERATIONS 100

typedef struct s_img
{
	void	*img_ptr;
	char	*img_addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_camera
{
	double	re_min;
	double	re_max;
	double	im_min;
	double	im_max;
	int		max_iter;
	int		colorshift;
}	t_camera;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_camera	cam;
	t_fractol	fractol;
}	t_data;

typedef struct fractol
{
	char	*name;
	t_z		input;
}	t_fractol;

typedef struct s_z
{
	int	x;
	int	y;
}	t_z;
//main.c
int		main(int argc, char **argv);
int		ft_close(t_data *data);
int		ft_keypress(int keycode, t_data *data);
//render.c
void	color_pixel(t_img *img, int x, int y, int color);
void	render(t_data *data);
//window.c
void	pixel_to_image(t_data *data, int x, int y, int color);
void	init_image(t_data *data);
void	defaultcamera(t_data *data);
//fractol.c
int		get_fractol_count(int x, int y);
int		count_to_color(int count, int color_shift, int max_iter);
int		determinefractol(int argc, char **argv, t_data *data);

#endif
