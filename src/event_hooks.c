/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:36:45 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/10 16:36:48 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ev_destroy(t_glob *g)
{
	if (!g->mlx.mlx)
		return (exit(-1), 1);
	ft_loop_end(g);
	if (g->mlx.canvas.ptr)
		mlx_destroy_image(g->mlx.mlx, g->mlx.canvas.ptr);
	if (g->mlx.win)
		mlx_destroy_window(g->mlx.mlx, g->mlx.win);
	free(g->world.objs);
	free(g->world.lights);
	ft_destroy_display(g);
	free(g->mlx.mlx);
	return (exit(0), 0);
}

int	ev_keypressed(int keycode, t_glob *g)
{
	if (keycode == KEY_ESC)
		ev_destroy(g);
	if (keycode == KEY_A)
		g->world.cam.pos = vec_sub(g->world.cam.pos,
				vec_mult(vec_cross(vec3(0, 1, 0), g->world.cam.normal), 0.1));
	if (keycode == KEY_D)
		g->world.cam.pos = vec_add(g->world.cam.pos,
				vec_mult(vec_cross(vec3(0, 1, 0), g->world.cam.normal), 0.1));
	if (keycode == KEY_W)
		g->world.cam.pos = vec_add(g->world.cam.pos,
				vec_mult(g->world.cam.normal, 0.1));
	if (keycode == KEY_S)
		g->world.cam.pos = vec_sub(g->world.cam.pos,
				vec_mult(g->world.cam.normal, 0.1));
	if (keycode == KEY_UP)
		g->world.cam.pos.y += double_to_fixed(0.5);
	if (keycode == KEY_DOWN)
		g->world.cam.pos.y -= double_to_fixed(0.5);
	if (keycode == KEY_RIGHT)
		g->world.cam.normal = matrx_rotatate_y(g->world.cam.normal, 10.0);
	if (keycode == KEY_LEFT)
		g->world.cam.normal = matrx_rotatate_y(g->world.cam.normal, -10.0);
	g->mlx.frame = 0;
	return (0);
}

int	ev_mouse(int btn, int x, int y, t_glob *g)
{
	(void)(x);
	(void)(y);
	if (btn == 4 && fixed_to_double(g->world.cam.fov) > 5)
		g->world.cam.fov -= double_to_fixed(5);
	if (btn == 5 && fixed_to_double(g->world.cam.fov) < 175)
		g->world.cam.fov += double_to_fixed(5);
	return (0);
}

int	hooks(t_glob *g)
{
	if (mlx_hook(g->mlx.win, STATIC_DESTROY, 0L, ev_destroy, g)
		+ mlx_key_hook(g->mlx.win, ev_keypressed, g)
		+ mlx_mouse_hook(g->mlx.win, ev_mouse, g)
		+ mlx_loop_hook(g->mlx.mlx, draw, g)
		+ mlx_loop(g->mlx.mlx) != 0)
		return (ev_destroy(g));
	return (0);
}
