/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 05:28:00 by olopez-s          #+#    #+#             */
/*   Updated: 2025/05/02 05:16:36 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	julia(t_complex z, t_complex c, int max_iter)
{
	int		iter;
	double	tmp;

	iter = 0;
	while (z.re * z.re + z.im * z.im <= 4.0 && iter < max_iter)
	{
		tmp  = z.re * z.re - z.im * z.im + c.re;
		z.im = 2.0 * z.re * z.im + c.im;
		z.re = tmp;
		iter++;
	}
	return (iter);
}

void draw_julia_pixel(t_data *data, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			iter;
	int			color;

	z.re = map_x(x, data);
	z.im = map_y(y, data);
	c.re = -0.7;
	c.im =  0.27015;
	iter  = julia(z, c, data->max_iter);
	color = get_color(iter, data->max_iter);
	loop_pixels(data, x, y, color);
}
