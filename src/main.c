/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 01:36:59 by olopez-s          #+#    #+#             */
/*   Updated: 2025/04/14 23:55:49 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


#include "../includes/fractol.h"

int	main(void)
{
	t_data	fractol;

	fractol.mlx = mlx_init();
	if (!fractol.mlx)
		return (1);

	fractol.win = mlx_new_window(fractol.mlx, WIDTH, HEIGHT, "Fractal Window");
	if (!fractol.win)
		return (1);

	fractol.img = mlx_new_image(fractol.mlx, WIDTH, HEIGHT);
	if (!fractol.img)
		return (1);

	fractol.addr = mlx_get_data_addr(fractol.img, &fractol.bpp, &fractol.line_len, &fractol.endian);
	if (!fractol.addr)
		return (1);

	ft_render(&fractol);

	mlx_put_image_to_window(fractol.mlx, fractol.win, fractol.img, 0, 0);

	mlx_key_hook(fractol.win, des_wind, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}

