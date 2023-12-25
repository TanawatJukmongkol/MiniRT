/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:29:43 by tjukmong          #+#    #+#             */
/*   Updated: 2023/12/25 08:28:42 by Tanawat J.       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	get_pixel_dirr(t_glob *g, int x, int y)
{
	double focal = 1;
	double vw = tanf(fixed_to_double(g->world.cam.fov) * ONE_RAD * 0.5) * focal;
	double vh = vw / g->mlx.aspect_ratio;
	t_vec3 dirr;
	t_vec3 u;
	t_vec3 v;

	vec_set(&u, vec_cross(g->world.cam.normal, vec3(0, 0, 1))); // alignment vec x up vector
	vec_set(&v, vec_cross(u, g->world.cam.normal)); // u x look_at
	
	// Set u, v to length of half viewport width, height modified by x, y.
	vec_set(&u, vec_mult(u, (((float)x / g->mlx.width) - 0.5) * vw));
	vec_set(&v, vec_mult(v, (((float)(g->mlx.height - y) / g->mlx.height) - 0.5) * vh));

	vec_set(&u, vec_add(u, vec_mult(g->world.cam.normal, focal))); // Add focus vector
	vec_set(&v, vec_add(v, vec_mult(g->world.cam.normal, focal))); // Add focus vector

	vec_set(&dirr, vec_norm(vec_add(
				vec_mult(g->world.cam.normal, focal),
				vec_add(u, v))));

	// printf("< %f, %f, %f >\n", fixed_to_double(dirr.x), fixed_to_double(dirr.y), fixed_to_double(dirr.z));

	return dirr;
}

void	fragment_renderer(
	t_glob *g, int chunk_nbr, t_color frag(
			t_mlx *ctx, t_world *world, t_ray ray))
{
	int		x;
	int		y;
	int		h;
	t_ray	r;

	h = g->mlx.height >> 2;
	y = h * chunk_nbr;
	h += y;
	vec_set(&g->world.cam.normal, vec_norm(g->world.cam.normal));
	while (y < h)
	{
		x = 0;
		while (x < g->mlx.width)
		{
			vec_set(&r.origin, g->world.cam.pos);
			vec_set(&r.direction, get_pixel_dirr(g, x, y));
			// Anti alias
			//vec_set(&r.direction, vec_mult(
			//		r.direction, 1 - (
			//			(float)rand() / RAND_MAX / 18e3)));
			putpixel(&g->mlx, x, y, frag(&g->mlx, &g->world, r));
			x++;
		}
		y++;
	}
}

t_color	fragment(t_mlx *ctx, t_world *w, t_ray r)
{
	t_color		c_light;
	t_hittable	record;
	size_t		i;

	(void)(ctx);

	vec_set(&record.norm, vec3(0, 0, 0));
	record.t = -1;

	i = 0;
	while (i < w->obj_count)
		hittable(&record, w->objs[i++], r);

	if (record.t != -1)
	{
		set_color(&c_light, rgb(
					(fixed_to_double(record.norm.x) + 1) * 127,
					(fixed_to_double(-record.norm.y) + 1) * 127,
					(fixed_to_double(record.norm.z) + 1) * 127 ));
		// set_color(&c_light, rgb(
					// (fixed_to_double(record.norm.x) + 1) * 127, 0, 0));
					// 0, (fixed_to_double(-record.norm.y) + 1) * 127, 0));
					// 0, 0, (fixed_to_double(record.norm.z) + 1) * 127 ));
	}
	else
		set_color(&c_light, w->ambient);

	return c_light;
}

int	draw(t_glob *g)
{
	if (g->mlx.frame >= 16)
	{
		g->mlx.frame %= 4;
		return (update_canvas(&g->mlx));
	}
	// mlx_string_put(g->mlx.mlx, g->mlx.win, 10, 10, rgb_to_hex(rgb(255,255,255)), "Loading...");
	fragment_renderer(g, g->mlx.frame % 4, fragment);
	g->mlx.frame++;
	return (update_canvas(&g->mlx));
}

int	ev_destroy(t_glob *g)
{
	if (!g->mlx.mlx)
		exit(-1);
	ft_loop_end(g);
	if (g->mlx.canvas.ptr)
		mlx_destroy_image(g->mlx.mlx, g->mlx.canvas.ptr);
	if (g->mlx.win)
		mlx_destroy_window(g->mlx.mlx, g->mlx.win);
	ft_destroy_display(g);
	free(g->mlx.mlx);
	exit(0);
	return (0);
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
		g->world.cam.pos.z += double_to_fixed(0.1);
	if (keycode == KEY_S)
		g->world.cam.pos.z -= double_to_fixed(0.1);
	if (keycode == KEY_UP)
		g->world.cam.pos.y += double_to_fixed(0.5);
	if (keycode == KEY_DOWN)
		g->world.cam.pos.y -= double_to_fixed(0.5);
	if (keycode == KEY_RIGHT && fixed_to_double(g->world.cam.fov) > 5)
		g->world.cam.fov -= double_to_fixed(5);
	if (keycode == KEY_LEFT && fixed_to_double(g->world.cam.fov) < 175)
		g->world.cam.fov += double_to_fixed(5);
	g->mlx.frame += 15;
	return 0;
}

int	main(void)
{
	t_glob	g;

	g.world.obj_count = 2;
	t_object obj[g.world.obj_count];


	if (init_canvas(&g.mlx, "MiniRT", 1000, 800) < 0)
		ev_destroy(&g);

	// Setup world
	g.world.cam.normal = vec3(0, 1, 0);
	g.world.cam.fov = double_to_fixed(95);
	g.world.cam.pos = vec3(0, -20, 0);
	g.world.ambient = rgb(0, 0, 0);
	
	// Read objects
	obj[0].type = sphere;
	obj[0].pos = vec3(0, 0, 0);
	obj[0].size = double_to_fixed(1);

	obj[1].type = sphere;
	obj[1].pos = vec3(0, 0, 1.3);
	obj[1].size = double_to_fixed(0.7);
	
	g.world.objs = obj;

	srand(141337);
	mlx_hook(g.mlx.win, STATIC_DESTROY, 0L, ev_destroy, &g);
	mlx_key_hook(g.mlx.win, ev_keypressed, &g);
	mlx_loop_hook(g.mlx.mlx, draw, &g);
	mlx_loop(g.mlx.mlx);
	return (0);
}
