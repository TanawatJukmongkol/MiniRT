
#include "minirt.h"

int	ev_destroy(t_glob *g)
{
	if (!g->mlx.mlx)
		exit(-1);
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

int ev_keypressed(int keycode, t_glob *g)
{
	// printf("keycode: %d\n", keycode);
	if (keycode == KEY_ESC)
		ev_destroy(g);
	if (keycode == KEY_A)
		g->world.cam.pos.x -= double_to_fixed(0.1);
	if (keycode == KEY_D)
		g->world.cam.pos.x += double_to_fixed(0.1);
	if (keycode == KEY_W)
		g->world.cam.pos.y += double_to_fixed(0.1);
	if (keycode == KEY_S)
		g->world.cam.pos.y -= double_to_fixed(0.1);
	if (keycode == KEY_UP)
		g->world.cam.pos.z += double_to_fixed(0.5);
	if (keycode == KEY_DOWN)
		g->world.cam.pos.z -= double_to_fixed(0.5);
	if (keycode == KEY_RIGHT && fixed_to_double(g->world.cam.fov) > 5)
		g->world.cam.fov -= double_to_fixed(5);
	if (keycode == KEY_LEFT && fixed_to_double(g->world.cam.fov) < 175)
		g->world.cam.fov += double_to_fixed(5);
	g->mlx.frame = 0;
	return 0;
}

