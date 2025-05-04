/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 05:06:56 by olopez-s          #+#    #+#             */
/*   Updated: 2025/05/03 01:58:06 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

unsigned int	get_color(int iter, int max_iter)
{
	int	shade;

	if (iter == max_iter)
		return (0x000000);
	shade = 255 * iter / max_iter;
	return ((shade << 16) | (shade << 8) | shade);
}
