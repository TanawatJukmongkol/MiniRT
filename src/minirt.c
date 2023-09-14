/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:29:43 by tjukmong          #+#    #+#             */
/*   Updated: 2023/09/05 01:04:16 by Tanawat J.       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ev_destroy(void *w)
{
	t_mlx	*window;

	window = (t_mlx *)w;
	if (!window->mlx)
		exit(-1);
	mlx_loop_end(window->mlx);
	if (window->canvas.ptr)
		mlx_destroy_image(window->mlx, window->canvas.ptr);
	if (window->win)
		mlx_destroy_window(window->mlx, window->win);
	mlx_destroy_display(window->mlx);
	free(window->mlx);
	exit(0);
	return (0);
}

void	draw(t_mlx *ctx)
{
	for (int y = 0; y < ctx->height; y++)
		for (int x = 0; x < ctx->width; x++)
			putpixel(ctx, x, y, rgba_to_hex(((float)x / ctx->width) * 255, ((float)y / ctx->height) * 255, ((float)(x * y) / (ctx->width * ctx->height)) * 255, 255));
	update_canvas(ctx);
}

int ev_resize(void *ctx)
{
	XWindowAttributes	attr;
	t_mlx				*window;

	window = (t_mlx *)ctx;
	XGetWindowAttributes(((t_xvar *)window->mlx)->display, (
			(t_win_list *)window->win)->window, &attr);
	window->width = attr.width;
	window->height = attr.height;
	draw(window);
	return (0);
}

int	main(void)
{
	t_mlx	w;

	if (init_canvas(&w, "MiniRT", 1000, 800) < 0)
		ev_destroy(&w);

	draw(&w);
	mlx_hook(w.win, DestroyNotify, 0L, ev_destroy, &w);
	mlx_hook(w.win, 0, StructureNotifyMask, NULL, &w);
	mlx_hook(w.win, ConfigureNotify, 0L, ev_resize, &w);
	mlx_loop(w.mlx);
	return (0);
}
