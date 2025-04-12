/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:53:03 by olopez-s          #+#    #+#             */
/*   Updated: 2025/04/06 01:14:12 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	loop_pixels(t_data *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dest = color;
}

void	render(t_data img)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while(HEIGHT > y)
	{	
		x = 0;
		while(WIDTH > x)
		{
			color = ((x * 255 / WIDTH) << 16) | (y * 255 / HEIGHT);
			loop_pixels(img.img, x, y, color);
			x++;
		}
		y++;
	}
}