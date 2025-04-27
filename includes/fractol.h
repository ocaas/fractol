/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 01:37:40 by olopez-s          #+#    #+#             */
/*   Updated: 2025/04/28 01:37:18 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define WIDTH 1000
# define HEIGHT 1000
# define ESC_KEY 65307
# define MLX_ERROR 1
# define ZOOM_IN 61
# define ZOOM_OUT 45
# define MANDELBROT 0 
# define JULIA 1


typedef struct t_data
{
	void	*mlx;
	void	*img;
	void	*win;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;

	int 	fractal_type;
	int		color_shift;
	double	offset_x;
	double	offset_y;
	double	zoom;
	int		max_iter;
	//int		c_imag; //sumar +1
	//int		c_real; //sumar +1
}	t_data;

typedef struct t_complex
{
	double		re; //real
	double		im; //imaginary 
}	t_complex;

void	ft_render(t_data *img);
void	loop_pixels(t_data *img, int x, int y, int color);
int		key_handle(int keycode, t_data *data);
int		error_check(t_data *data);
void 	zoom_handle(int keycode, t_data *data);
int		mandelbrot(t_complex c, int max_iter);
void	mandelbrot_pixel(t_data *data, int x, int y);
double	map_x(int x, t_data *data);
double	map_y(int y, t_data *data);
void	draw_mandelbrot(t_data *data);

#endif