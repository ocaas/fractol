/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 01:36:59 by olopez-s          #+#    #+#             */
/*   Updated: 2025/04/26 03:02:03 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(void)
{
	t_data	fractol;

	fractol.mlx = mlx_init();
	if (error_check(&fractol) == MLX_ERROR)
		return (MLX_ERROR);
	fractol.win = mlx_new_window(fractol.mlx, 1000, 1000, "window");
	fractol.img = mlx_new_image(fractol.mlx, 1000, 1000);
	fractol.addr = mlx_get_data_addr(fractol.img, &fractol.bpp,
			&fractol.line_len, &fractol.endian);
	fractol.zoom = 1.0;
	fractol.offset_x = 0.0;
	fractol.offset_y = 0.0;
	ft_render(&fractol);
	mlx_put_image_to_window(fractol.mlx, fractol.win, fractol.img, 0, 0);
	mlx_key_hook(fractol.win, (int (*)())des_wind, &fractol);
	mlx_key_hook(fractol.win, (int (*)())zoom, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
