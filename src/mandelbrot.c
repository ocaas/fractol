/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 02:02:33 by olopez-s          #+#    #+#             */
/*   Updated: 2025/04/27 05:57:59 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


int     mandelbrot(t_complex c, int max_iter);
{
    t_complex z;
    int       iter;
    double    tmp;

    z.re = 0;
    z.im = 0;
    iter = 0;
    while (z.re * z.re + z.im * z.im <= 4 && iter < max_iter)
    {
        tmp   = z.re * z.re - z.im * z.im + c.re;
        z.im  = 2 * z.re * z.im + c.im;
        z.re  = tmp;
        iter++;
    }
    return (iter);
}

void	mandelbrot_pixel(t_data *data, int x, int y)
{
	double	real;
	double	imag;
	int		iter;
	int		color;

	real = map_x(x, data);
	imag = map_y(y, data);
	iter = mandelbrot(real, imag, data);
	color = get_fractal_color(iter, data->max_iter, data->color_shift);
	put_pixel_to_image(data, x, y, color);
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
			draw_mandelbrot_pixel(data, x, y);
			x++;
		}
		y++;
	}
}