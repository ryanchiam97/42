/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:43:08 by rchiam            #+#    #+#             */
/*   Updated: 2025/09/30 22:53:15 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx_linux/mlx.h"
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
	void	*ptr;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_var
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_var;

typedef struct s_z
{
	int	x;
	int	y;
}	t_z;

int			main(void);
void		color_pixel(t_img *img, int x, int y, int color);
void		render(t_var *data);
void		pixel_to_image(t_var *data, int x, int y, int color);
static int	ft_close(t_var *data);
int			ft_keypress(int keycode, t_var *data);
void		init_image(t_var *data);

#endif
