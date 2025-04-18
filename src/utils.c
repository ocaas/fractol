/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 01:37:04 by olopez-s          #+#    #+#             */
/*   Updated: 2025/04/15 05:39:13 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	mlx_error(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (MLX_ERROR);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fract-ol");
	if (!data->win)
		return (MLX_ERROR);
	return (0);
}

static int	img_error(t_data *data)
{
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (MLX_ERROR);
	}
	data->img = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_len, &data->endian);
	if (!data->img)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (MLX_ERROR);
	}
	return (0);
}

int	error_check(t_data *data)
{
	if (mlx_error(data) == MLX_ERROR)
		return (1);
	if (img_error(data) == MLX_ERROR)
		return (1);
	return (0);
}
