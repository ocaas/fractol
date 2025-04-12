/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 01:37:40 by olopez-s          #+#    #+#             */
/*   Updated: 2025/04/13 00:35:26 by olopez-s         ###   ########.fr       */
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

typedef struct t_data
{
	void	*mlx;
	void	*img;
	void	*win;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}t_data;

typedef struct t_complex
{
	int		re; //real
	int		im; //imaginary 
}t_complex;

void	ft_render(t_data *img);
void	loop_pixels(t_data *img, int x, int y, int color);
int		mandelbrot(t_complex c);
int		des_wind(int keycode, t_data *data);
int		mandelbrot(t_complex *c)
//funct

#endif