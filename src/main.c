/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 01:36:59 by olopez-s          #+#    #+#             */
/*   Updated: 2025/04/15 00:22:56 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


int main (void)
{
	t_data	fractol;

	fractol.mlx = mlx_init();
	if (!fractol.mlx)
		return (1);
	
	fractol.win = mlx_new_window(fractol.mlx, 800, 800, "window");
	fractol.img = mlx_new_image(fractol.mlx, 600, 500);
	fractol.addr = mlx_get_data_addr(fractol.mlx, &fractol.bpp, &fractol.line_len, &fractol.endian);

	//missing something here
	ft_render(&fractol);
	mlx_put_image_to_window(fractol.mlx, fractol.win, fractol.img, 0, 0);
	mlx_key_hook(fractol.win, (int (*)())des_wind, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
