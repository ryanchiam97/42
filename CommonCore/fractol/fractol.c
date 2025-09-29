/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:43:21 by rchiam            #+#    #+#             */
/*   Updated: 2025/09/22 21:49:32 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// mandelbrot
// z_n+1 = z^2_n + c
// z_0 = 0 + 0i
// c = pixel coords

// julia
// z_n+1 = z^2_n + c
// z_0 = pixel coords
// c = input complex number

// for both, 
// count the number of iterations 
// until 
// |z_n| > 2 
// or 
// x^2 + y^2 > 4 (equivlent)
// colour the pixel according to the iterations
// if count = MAX_ITERATION (eg 100), set as black

//mlx slides
//https://www.canva.com/design/DAGT6G8aJHY/fqork5u1hxZONk8a4WQtdQ/view
