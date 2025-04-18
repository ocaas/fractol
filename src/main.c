/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 01:36:59 by olopez-s          #+#    #+#             */
/*   Updated: 2025/04/15 05:37:57 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(void)
{
	t_data	fractol;

	fractol.mlx = mlx_init();
	if (error_check(&fractol) == MLX_ERROR)
		return (MLX_ERROR);
	fractol.win = mlx_new_window(fractol.mlx, 800, 800, "window");
	fractol.img = mlx_new_image(fractol.mlx, 800, 800);
	fractol.addr = mlx_get_data_addr(fractol.img, &fractol.bpp,
			&fractol.line_len, &fractol.endian);
	ft_render(&fractol);
	mlx_put_image_to_window(fractol.mlx, fractol.win, fractol.img, 0, 0);
	mlx_key_hook(fractol.win, (int (*)())des_wind, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
