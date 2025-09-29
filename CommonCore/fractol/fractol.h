/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:43:08 by rchiam            #+#    #+#             */
/*   Updated: 2025/09/30 00:26:53 by rchiam           ###   ########.fr       */
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


#endif
