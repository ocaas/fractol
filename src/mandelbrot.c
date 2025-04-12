/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 02:02:33 by olopez-s          #+#    #+#             */
/*   Updated: 2025/04/13 01:52:37 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot(t_complex c)
{
	t_complex z;
	int		iter;
	double	tmp;

	z.re = 0;
	z.im = 0;
	iter = 0;
	while (z.re * z.re + z.im * z.im <= 4 && iter < 100)
	{
		tmp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = tmp;
		iter++;
	}
	return (iter);
}
