/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 07:47:44 by olopez-s          #+#    #+#             */
/*   Updated: 2025/04/26 05:19:22 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_handle(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);	
	}
	zoom_handle(keycode, data);
	return (0);
}

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
}
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
	return (0);*/
