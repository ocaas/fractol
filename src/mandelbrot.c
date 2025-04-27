/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 02:02:33 by olopez-s          #+#    #+#             */
/*   Updated: 2025/04/28 01:40:51 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int     mandelbrot(t_complex c, int max_iter)
{
    t_complex z;
    int       iter;
    double    tmp;

    z.re = 0;
    z.im = 0;
    iter = 0;
    while (z.re * z.re + z.im * z.im <= 4.0 && iter < max_iter)
    {
        tmp   = z.re * z.re - z.im * z.im + c.re;
        z.im  = 2.0 * z.re * z.im + c.im;
        z.re  = tmp;
        iter++;
    }
    return (iter);
}

void	mandelbrot_pixel(t_data *data, int x, int y)
{
	t_complex p;
	int		iter;
	int		color;

	p.re = map_x(x, data);
	p.im = map_y(y, data);
	iter = mandelbrot(p, data->max_iter);
	if(iter == data->max_iter)
		color = 0x000000;
	else
		color = (int)((double)iter / data->max_iter * 0xFFFFFF);
	loop_pixels(data, x, y, color);
}

void	draw_mandelbrot(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mandelbrot_pixel(data, x, y);
			x++;
		}
		y++;
	}
}
