/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 07:47:44 by olopez-s          #+#    #+#             */
/*   Updated: 2025/04/15 01:12:00 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int des_wind(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}
	return(0);
}
	/*handle_movement(keycode, data);
	handle_zoom(keycode, data);
	apply_color_change(keycode, data);
	handle_lorenz_keys(keycode, data);
	render_fractal(data);
	return (0);*/
