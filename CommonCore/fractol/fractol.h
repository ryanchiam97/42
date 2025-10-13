/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:43:08 by rchiam            #+#    #+#             */
/*   Updated: 2025/10/13 23:16:06 by rchiam           ###   ########.fr       */
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
# include "ft_printf/ft_printf.h"
# include <math.h>

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITERATIONS 100

// # define MAX_ITERATIONS 50

# define COLORJUMP 3
# define COLORMOD 12
# define PANSPEED 0.05

# define R 5.0
# define G 1500.0
# define B 28.5

// # define R 9.0
// # define G 15.0
// # define B 8.5

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
	int		mx_iter;
	int		c_shift;
}	t_camera;

typedef struct s_z
{
	double	re;
	double	im;
}	t_z;

typedef struct s_fractol
{
	char	*name;
	t_z		z;
}	t_fractol;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_camera	cam;
	t_fractol	f;
}	t_data;

//main.c
int		main(int argc, char **argv);
int		ft_close(t_data *data);
int		determinefractol(int argc, char **argv, t_data *data);
int		cleanup(t_data *data);
int		handlejulia(t_data *data, char *name, char *str1, char *str2);
//render.c
void	color_pixel(t_img *img, double x, double y, int color);
void	render(t_data *data);
double	map_x(t_data *data, int x);
double	map_y(t_data *data, int y);
int		count_to_color(int count, int color_shift, int mx_iter);
//window.c
void	init_image(t_data *data);
void	defaultcamera(t_data *data);
int		ft_keypress(int keycode, t_data *data);
int		ft_mousehook(int button, int x, int y, t_data *data);
void	instructions(void);
//fractol.c
int		mandelbrot_count(double re, double im);
int		julia_count(double re, double im, t_data *data);
int		burningship_count(double re, double im);
int		get_fractol_count(double zx, double zy, double cx, double cy);
int		get_fractol_count_burningship(double zx, double zy, double cx,
			double cy);
//panzoom.c
void	zoom(t_data *data, int mouse_x, int mouse_y, double zoom);
void	pan(t_data *data, double re_shift, double im_shift);
void	colorshift(t_data *data);

#endif
