/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 07:47:44 by olopez-s          #+#    #+#             */
/*   Updated: 2025/04/13 01:20:02 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int des_wind(int keycode, void *param)
{
    t_data *data;

    data = (t_data *)param;
    if (keycode == ESC_KEY)
    {
        mlx_destroy_image(data->mlx, data->img);
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    return (0);
}
