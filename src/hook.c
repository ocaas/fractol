/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 07:47:44 by olopez-s          #+#    #+#             */
/*   Updated: 2025/04/29 22:57:09 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


static void close_cleanly(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int mouse_handle(int button, int x, int y, t_data *f)
{
	(void)x;
	(void)y;
	if (button == MOUSE_SCROLL_UP)
		f->zoom *= 0.95;
	if(button == MOUSE_SCROLL_DOWN)
		f->zoom *= 1.05;
    ft_render(f);
    return (0);
}

int key_handle(int keycode, t_data *f)
{
    if (keycode == ESC_KEY)
        close_cleanly(f);
    if (keycode == W_KEY || keycode == UP_ARROW)
        f->offset_y -= 0.2 / f->zoom;
    if (keycode == S_KEY || keycode == DOWN_ARROW)
        f->offset_y += 0.2 / f->zoom;
    if (keycode == A_KEY || keycode == LEFT_ARROW)
        f->offset_x -= 0.2 / f->zoom;
    if (keycode == D_KEY || keycode == RIGHT_ARROW)
        f->offset_x += 0.2 / f->zoom; 
    ft_render(f);
    return (0);
}

void handles(t_data	*data)
{
	mlx_hook(data->win, 2, 1L << 0, key_handle, data);
	mlx_hook(data->win, 4, 1L << 2, mouse_handle, data);
}

/*
void zoom_handle(int keycode, t_data *data)
{
	if (keycode == ZOOM_IN)
	{
		data->zoom *= 1.1;
		data->max_iter += 10;
	}
	else if (keycode == ZOOM_OUT)
	{
		data->zoom /= 1.1;
		if (data->max_iter > 30)
			data->max_iter -= 10;
	}
	ft_render(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
*/

/*
	if(keycode == ZOOM_IN)
		data->zoom *= 1.1;
	else if(keycode == ZOOM_OUT)
		data->zoom /= 1.1;
	else 
		return(0);
	ft_render(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return(0);
	*/
	/*handle_movement(keycode, data);

	Cuando muevas mandelbrot usas x_offset e y_offset 
	handle_zoom(keycode, data);
	apply_color_change(keycode, data);
	handle_lorenz_keys(keycode, data);
	render_fractal(data);
	return (0);
*/

/*
static void zoom_in(t_data *f)
{
    f->offset_x = (f->offset_x - (WIDTH / 2.0) * (4.0 / WIDTH) / f->zoom) *
		 1.2 + (WIDTH / 2.0) * (4.0 / WIDTH) / (f->zoom * 1.2);
    f->offset_y = (f->offset_y - (HEIGHT / 2.0) * (4.0 / HEIGHT) / f->zoom) * 
		1.2 + (HEIGHT / 2.0) * (4.0 / HEIGHT) / (f->zoom * 1.2);
    f->zoom *= 1.2;
}

static void zoom_out(t_data *f)
{
    f->offset_x = (f->offset_x - (WIDTH / 2.0) * (4.0 / WIDTH) / f->zoom) / 
		1.2 + (WIDTH / 2.0) * (4.0 / WIDTH) / (f->zoom / 1.2);
    f->offset_y = (f->offset_y - (HEIGHT / 2.0) * (4.0 / HEIGHT) / f->zoom) / 
		1.2 + (HEIGHT / 2.0) * (4.0 / HEIGHT) / (f->zoom / 1.2);
    f->zoom /= 1.2;
} */