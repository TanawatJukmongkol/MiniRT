/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:29:43 by tjukmong          #+#    #+#             */
/*   Updated: 2023/11/25 05:47:17 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	get_pixel_dirr(t_glob *g, int x, int y)
{
	t_vec3	px_centr;
	t_vec3	dirr;
	// Viewport u, v
	t_vec3	uv_o;
	t_vec3	u;
	t_vec3	v;
	// Delta u, v
	t_vec3	du;
	t_vec3	dv;
	// Get scene viewport size
	double	focal = 1.0;
	double	vh = 1.0;
	double	vw = vh * g->mlx.aspect_ratio;

	// vec_set(&dirr, vec3(x, y, 0));
	vec_set(&u, vec3(vw, 0, 0));
	vec_set(&v, vec3(0, -vh, 0));
	vec_set(&du, vec_mult(u, 1.0 / g->mlx.width));
	vec_set(&dv, vec_mult(v, 1.0 / g->mlx.height));

	vec_set(&uv_o, vec_add(
		vec_sub(
			vec_sub(
				vec_sub(g->world.cam.pos, vec3(0, 0, focal)),
				vec_mult(u, 0.5)
				),
			vec_mult(v, 0.5)
		),
		vec_mult(vec_add(du, dv), 0.5)
	));

	vec_set(&px_centr, vec_add(vec_add(uv_o, vec_mult(u, (float)x/g->mlx.width)), vec_mult(v, (float)y/g->mlx.height)));

	vec_set(&dirr, vec_sub(px_centr, g->world.cam.pos));

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

	h = g->mlx.height >> 5;
	y = h * chunk_nbr;
	h += y;
	while (y < h)
	{
		x = 0;
		while (x < g->mlx.width)
		{
			vec_set(&r.origin, vec3(0, 0, 0));
			vec_set(&r.direction, vec_norm(get_pixel_dirr(g, x, y)));
			// Anti alias
			vec_set(&r.direction, vec_mult(
					r.direction, 1 - (
						(float)rand() / RAND_MAX / 42)));
			putpixel(&g->mlx, x, y, frag(&g->mlx, &g->world, r));
			x++;
		}
		y++;
	}
}

int	hit_sphere(t_vec3 pos, double rad, t_ray r)
{
	t_vec3	r_norm;
	t_vec3	oc;
	double	a;
	double	b;
	double	c;

	vec_set(&r_norm, vec_norm(r.direction));
	vec_set(&oc, vec_sub(r.origin, pos));

	a = fixed_to_double(vec_dot(r_norm, r_norm));
	b = 2.0 * fixed_to_double(vec_dot(oc, r_norm));
	c = fixed_to_double(vec_dot(oc, oc)) - rad * rad;
	// printf("<%f,%f,%f>\n",
	// 	fixed_to_double(r_norm.x) ,
	// 	fixed_to_double(r_norm.y),
	// 	fixed_to_double(r_norm.z)
	// 	);
	return ((b * b) - (4 * a * c) >= 0);
}

// 1) color_invrt(&obj);
// 2) color_sub(&light, obj);
// 3) color_mult_norm(&light, normal);

t_color	fragment(t_mlx *ctx, t_world *w, t_ray r)
{
	t_color	c_light;
	// t_color	c_obj;
	(void)ctx;
	(void)w;
	(void)r;

	if (hit_sphere(vec3(0, 0, -1), 0.2, r))
		set_color(&c_light, rgb(255, 255, 255));
	else
	{
		set_color(&c_light, rgb(
			255 * fixed_to_double(r.direction.x),
			-255 * fixed_to_double(r.direction.y),
			80
		));
	}

	return c_light;
}

int	draw(t_glob *g)
{
	if (g->mlx.frame >= 32)
		return (update_canvas(&g->mlx));
	fragment_renderer(g, g->mlx.frame % 32, fragment);
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
 
#include <X11/X.h>

int ev_keypressed(int keycode, t_glob *g)
{
	// printf("keycode: %d\n", keycode);
	if (keycode == KEY_ESC)
		ev_destroy(g);
	return 0;
}

int	main(void)
{
	t_glob	g;

	if (init_canvas(&g.mlx, "MiniRT", 1000, 800) < 0)
		ev_destroy(&g);

	vec_set(&g.world.cam.pos, vec3(0, 0, 0));

	srand(141337);
	mlx_hook(g.mlx.win, STATIC_DESTROY, 0L, ev_destroy, &g);
	mlx_key_hook(g.mlx.win, ev_keypressed, &g);
	mlx_loop_hook(g.mlx.mlx, draw, &g);
	mlx_loop(g.mlx.mlx);
	return (0);
}
