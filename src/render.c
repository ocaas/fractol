/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:53:03 by olopez-s          #+#    #+#             */
/*   Updated: 2025/05/05 05:42:10 by olopez-s         ###   ########.fr       */
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

void	ft_render(t_data *f)
{
	int	x;
	int	y;

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
			if (f->fractal_type == MANDELBROT)
				mandelbrot_pixel(f, x, y);
			else
				draw_julia_pixel(f, x, y);
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
