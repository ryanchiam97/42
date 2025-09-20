/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:43:08 by rchiam            #+#    #+#             */
/*   Updated: 2025/09/20 18:38:29 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx_linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>

# define WIDTH 800
# define HEIGHT 600

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;


#endif
