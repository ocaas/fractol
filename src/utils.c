/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 01:37:04 by olopez-s          #+#    #+#             */
/*   Updated: 2025/05/02 05:08:47 by olopez-s         ###   ########.fr       */
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
	void	*img_ptr;

	img_ptr = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!img_ptr)
		return (MLX_ERROR);
	data->addr = mlx_get_data_addr(img_ptr, &data->bpp,
			&data->line_len, &data->endian);
	if (!data->addr)
	{
		mlx_destroy_image(data->mlx, img_ptr);
		return (MLX_ERROR);
	}
	data->img = img_ptr;          /* keep the real MLX image pointer */
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

double map_x(int x, t_data *data)
{
	return((x - WIDTH / 2.0) * (4.0 / WIDTH) / data->zoom + data->offset_x);
}

double map_y(int y, t_data *data)
{
	return((y - HEIGHT / 2.0) * (4.0 / HEIGHT) / data->zoom + data->offset_y);
}