/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 21:36:44 by rchiam            #+#    #+#             */
/*   Updated: 2025/10/04 17:16:44 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render(t_data *data)
{
	int	x;
	int	y;
	int	color;
	int	mappedx;
	int	mappedy;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = fractol(x, y, data);
			color_pixel(&data->img, x, y, color);
			x++;
		}
		y++;
	}
}

void	color_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->img_addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	mapX()

int mapY()
