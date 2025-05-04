/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 07:47:44 by olopez-s          #+#    #+#             */
/*   Updated: 2025/05/04 02:58:50 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	close_cleanly(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int	mouse_handle(int button, int x, int y, t_data *f)
{
	(void)x;
	(void)y;
	if (button == MOUSE_SCROLL_UP)
		f->zoom *= 0.95;
	if (button == MOUSE_SCROLL_DOWN)
		f->zoom *= 1.05;
	ft_render (f);
	return (0);
}

static void	ft_julia_move(int keycode, t_data *data)
{
	if (data->fractal_type == JULIA)
	{
		if (keycode == A_KEY)
		{
			data->julia_x -= 0.05;
			data->julia_y -= 0.05;
		}
		else if (keycode == D_KEY)
		{
			data->julia_x += 0.05;
			data->julia_y += 0.05;
		}
		else if (keycode == W_KEY)
		{
			data->julia_x -= 0.05;
			data->julia_y += 0.05;
		}
		else if (keycode == S_KEY)
		{
			data->julia_x += 0.05;
			data->julia_y -= 0.05;
		}
	}
}

int	key_handle(int keycode, t_data *f)
{
	if (keycode == ESC_KEY)
		close_cleanly(f);
	if (keycode == W_KEY || keycode == UP_ARROW)
		f->offset_y -= 0.2 / f->zoom;
	if (keycode == S_KEY || keycode == DOWN_ARROW)
		f->offset_y += 0.2 / f->zoom;
	if (keycode == A_KEY || keycode == LEFT_ARROW)
		f->offset_x -= 0.2 / f->zoom;
	if (keycode == D_KEY || keycode == RIGHT_ARROW)
		f->offset_x += 0.2 / f->zoom;
	if (keycode == PLUS_KEY || keycode == 65451)
		f->max_iter += 10;
	if ((keycode == MINUS_KEY || keycode == 65454) && f->max_iter > 20)
		f->max_iter -= 10;
	ft_julia_move(keycode, f);
	ft_render (f);
	return (0);
}

void	handles(t_data	*data)
{
	mlx_hook(data->win, 2, 1L << 0, key_handle, data);
	mlx_hook(data->win, 4, 1L << 2, mouse_handle, data);
	mlx_hook(data->win, 17, 1L << 17, close_cleanly, data);
}

/*
void zoom_handle(int keycode, t_data *data)
{
	if (keycode == ZOOM_IN)
	{
		data->zoom *= 1.1;
		data->max_iter += 10;
	}
	else if (keycode == ZOOM_OUT)
	{
		data->zoom /= 1.1;
		if (data->max_iter > 30)
			data->max_iter -= 10;
	}
	ft_render(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
*/

/*
	if(keycode == ZOOM_IN)
		data->zoom *= 1.1;
	else if(keycode == ZOOM_OUT)
		data->zoom /= 1.1;
	else 
		return(0);
	ft_render(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return(0);
	*/
	/*handle_movement(keycode, data);

	Cuando muevas mandelbrot usas x_offset e y_offset 
	handle_zoom(keycode, data);
	apply_color_change(keycode, data);
	handle_lorenz_keys(keycode, data);
	render_fractal(data);
	return (0);
*/
