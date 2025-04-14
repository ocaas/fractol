/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:53:03 by olopez-s          #+#    #+#             */
/*   Updated: 2025/04/14 23:55:59 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	loop_pixels(t_data *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dest = color;
}

void	ft_render(t_data *img)
{
	int			x;
	int			y;
	t_complex	c;
	int			iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.re = (double)x / WIDTH * 4.0 - 2.0;
			c.im = (double)y / HEIGHT * 4.0 - 2.0;
			iter = mandelbrot(c);
			if (iter == 100)
				loop_pixels(img->img, x, y, 0x000000); // black if inside
			else
				loop_pixels(img->img, x, y, iter * 1000); // color if outside
			x++;
		}
		y++;
	}
}

/*
ex. render has to covert each (x, y) pixel into complex numbers.
Apply the math loop (z = z^2 + c)
color the pixel depending how fast z escapes. 
*/