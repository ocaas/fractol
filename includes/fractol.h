/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 01:37:40 by olopez-s          #+#    #+#             */
/*   Updated: 2025/05/02 22:49:26 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define WIDTH 700
# define HEIGHT 700
# define ESC_KEY 65307
# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define RIGHT_ARROW 65363
# define LEFT_ARROW 65361
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5
# define MLX_ERROR 1
# define PLUS_KEY 61
# define MINUS_KEY 45
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

void			ft_render(t_data *img);
void			loop_pixels(t_data *img, int x, int y, int color);
int				key_handle(int keycode, t_data *data);
int				error_check(t_data *data);
void 			zoom_handle(int keycode, t_data *data);
int				mandelbrot(t_complex c, int max_iter);
void			mandelbrot_pixel(t_data *data, int x, int y);
double			map_x(int x, t_data *data);
double			map_y(int y, t_data *data);
void			draw_mandelbrot(t_data *data);
void			handles(t_data *data);
int				julia(t_complex z, t_complex c, int max_iter);
void			draw_julia_pixel(t_data *data, int x, int y);
unsigned int	get_color(int iter, int max_iter);
int				ft_strcmp(const char *s1, const char *s2);
float			ft_atof(char *s);
int				ft_parse(char *s);
void			ft_putstr(char const *s);

#endif