/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:28:25 by tjukmong          #+#    #+#             */
/*   Updated: 2023/11/23 13:35:22 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_null_mlx(t_mlx *window)
{
	window->title = NULL;
	window->mlx = NULL;
	window->win = NULL;
	window->canvas.ptr = NULL;
	window->canvas.buff = NULL;
	window->frame = 0;
}

int	init_canvas(t_mlx *window, char *title, int w, int h)
{
	set_null_mlx(window);
	window->title = title;
	window->width = w;
	window->height = h;
	window->mlx = mlx_init();
	window->aspect_ratio = (double)w / h;
	if (!window->mlx)
		return (-1);
	window->win = mlx_new_window(window->mlx,
			window->width, window->height, window->title);
	if (!window->win)
		return (-1);
	window->canvas.ptr = mlx_new_image(window->mlx,
			window->width, window->height);
	if (!window->canvas.ptr)
		return (-1);
	window->canvas.buff = mlx_get_data_addr(window->canvas.ptr,
			&window->canvas.px_bits, &window->canvas.ln_bytes,
			&window->canvas.endian);
	if (!window->canvas.buff)
		return (-1);
	return (0);
}

int	update_canvas(t_mlx *window)
{
	return (mlx_put_image_to_window(
			window->mlx, window->win, window->canvas.ptr, 0, 0));
}
