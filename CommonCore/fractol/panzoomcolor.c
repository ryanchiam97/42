/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panzoomcolor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 21:48:05 by rchiam            #+#    #+#             */
/*   Updated: 2025/10/12 16:23:36 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_data *data, int mouse_x, int mouse_y, double zoom)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = map_x(data, mouse_x);
	mouse_im = map_y(data, mouse_y);
	data->cam.re_min = mouse_re - (mouse_re - data->cam.re_min) / zoom;
	data->cam.re_max = mouse_re + (data->cam.re_max - mouse_re) / zoom;
	data->cam.im_min = mouse_im - (mouse_im - data->cam.im_min) / zoom;
	data->cam.im_max = mouse_im + (data->cam.im_max - mouse_im) / zoom;
}

void	pan(t_data *data, double re_shift, double im_shift)
{
	double	shift;

	if (re_shift != 0)
	{
		shift = (data->cam.re_max - data->cam.re_min) * re_shift;
		data->cam.re_min += shift;
		data->cam.re_max += shift;
		return ;
	}
	if (im_shift != 0)
	{
		shift = (data->cam.im_max - data->cam.im_min) * im_shift;
		data->cam.im_min += shift;
		data->cam.im_max += shift;
		return ;
	}
}

void	colorshift(t_data *data)
{
	data->cam.c_shift += COLORJUMP;
	data->cam.c_shift %= COLORMOD;
	return ;
}
