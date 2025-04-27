/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:53:03 by olopez-s          #+#    #+#             */
/*   Updated: 2025/04/27 05:59:33 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	loop_pixels(t_data *img, int x, int y, int color)
{
	char	*dest;

	if (!img || !img->addr || x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	dest = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dest = color;
}

void ft_render(t_data *f)
{
    int	x;
	int	y;
	int iter;
    t_complex c;

    y = 0;
    if (f->img)
        mlx_destroy_image(f->mlx, f->img);
    f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
    f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);

    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            mandelbrot_pixel(f, x, y);
			x++;
        }
        y++;
    }
    mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

int	get_fractal_color(int iter, int max_iter, int color_shift)
{
	int	red;
	int	green;
	int	blue;

	if (iter >= max_iter)
		return (0x000000);
	red = (iter * (9 + color_shift)) % 256;
	green = (iter * (5 + color_shift)) % 256;
	blue = (iter * (11 + color_shift)) % 256;
	return ((red << 16) | (green << 8) | blue);
}


/*
void	ft_render(t_data *img)
{
	int			i;
	int			x;
	int			y;
	t_complex	c;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
            c.re = ((double)x / WIDTH) * (4.0 / img->zoom) - (2.0 / img->zoom) + img->offset_x;
            c.im = ((double)y / HEIGHT) * (4.0 / img->zoom) - (2.0 / img->zoom) + img->offset_y;

			i = mandelbrot(c);
			if (i == 100)
				loop_pixels(img, x, y, 0x000000);
			else
				loop_pixels(img, x, y, i * 1000);
			x++;
		}
		y++;
	}
}
*/


/*
ex. render has to covert each (x, y) pixel into complex numbers.
Apply the math loop (z = z^2 + c)
color the pixel depending how fast z escapes. 
*/


/*

void ft_render(t_data *f)
{
    int         x;
    int         y;
    t_complex   c;
    int         iter;

    //recreate image buffer
    if (f->img)
        mlx_destroy_image(f->mlx, f->img);
    f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
    f->addr = mlx_get_data_addr(f->img, &f->bpp,
                                &f->line_len, &f->endian);
    draw each pixel 
    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
			c.re = ((double)x - WIDTH / 2.0) * (4.0 / WIDTH) / f->zoom + f->offset_x;
			c.im = ((double)y - HEIGHT / 2.0) * (4.0 / HEIGHT) / f->zoom + f->offset_y;

            iter = mandelbrot(c);
            loop_pixels(f, x, y, (iter == f->max_iter) ? 0x000000
                                                      : iter * 1000);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
*/