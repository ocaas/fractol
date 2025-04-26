/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 01:37:40 by olopez-s          #+#    #+#             */
/*   Updated: 2025/04/26 05:16:49 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 800
# define ESC_KEY 65307
# define MLX_ERROR 1
# define ZOOM_IN 61
# define ZOOM_OUT 45
# define JULIS 1


typedef struct t_data
{
	void	*mlx;
	void	*img;
	void	*win;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;

	int		offset_x;
	int		offset_y;
	int		zoom;
	int		max_iter;
	//int		c_imag; //sumar +1
	//int		c_real; //sumar +1
}	t_data;

typedef struct s_complex
{
	double		re; //real
	double		im; //imaginary 
}	t_complex;

void	ft_render(t_data *img);
void	loop_pixels(t_data *img, int x, int y, int color);
int		mandelbrot(t_complex c);
int		key_handle(int keycode, t_data *data);
int		error_check(t_data *data);
void zoom_handle(int keycode, t_data *data);

#endif