/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:29:43 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/08 17:16:52 by Tanawat J.       ###   ########.fr       */
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

	vec_set(&u, vec_add(u, vec_mult(g->world.cam.normal, focal))); // Add focus vector
	vec_set(&u, vec_cross(g->world.cam.normal, vec3(0, -1, 0))); // alignment vec x up vector
	vec_set(&v, vec_cross(u, g->world.cam.normal)); // u x look_at

	// Set u, v to length of half viewport width, height modified by x, y.
	vec_set(&u, vec_mult(u, (((float)x / g->mlx.width) - 0.5) * vw));
	vec_set(&v, vec_mult(v, ((((float)g->mlx.height - y) / g->mlx.height) - 0.5) * vh));

	vec_set(&dirr, vec_norm(vec_add(
				vec_mult(g->world.cam.normal, focal),
				vec_add(u, v))));

	// printf("< %f, %f, %f >\n", fixed_to_double(dirr.x), fixed_to_double(dirr.y), fixed_to_double(dirr.z));
	return dirr;
}

void	fragment_renderer(
	t_glob *g, int chunk_nbr, t_color frag(
			t_mlx *ctx, t_world *world, t_ray ray, t_hittable *rec))
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
			g->hit_record.n = 0;
			vec_set(&r.origin, g->world.cam.pos);
			vec_set(&r.direction, get_pixel_dirr(g, x, y));
			putpixel(&g->mlx, x, y, frag(&g->mlx, &g->world, r, &g->hit_record));
			x++;
		}
		y++;
	}
}

t_color	fragment(t_mlx *ctx, t_world *w, t_ray r, t_hittable *rec)
{
	t_color		c_light;
	(void)(ctx);

	vec_set(&rec->norm, r.direction);
	rec->t = -1;
	rec->intensity = w->light_count;

	hittable(w, rec, r);
	set_color(&c_light, w->ambient);

	if (rec->t == -1)
		return (color_mult_norm(c_light, fixed_to_double(w->amb_brightness)));

	lighting(w, rec, r);
	set_color(&c_light, color_sub(rec->color, color_invrt(w->ambient)));
	set_color(&c_light, rec->color);
	return (color_mult_norm(c_light,
				fixed_to_double(w->amb_brightness)
				+ rec->intensity / w->light_count));
}

int	draw(t_glob *g)
{
	if (g->mlx.frame >= 4)
		return (update_canvas(&g->mlx));
	fragment_renderer(g, g->mlx.frame % 4, fragment);
	g->mlx.frame++;
	return (update_canvas(&g->mlx));
}

int	main(int argc, char **argv)
{
	t_glob		g;

	(void)argc;
	set_ele(&g.world.ele);

	if (check_file(argc, argv, &g.world.ele) == 0)
		return (1);
	pass_element(argv, &g.world);

	if (init_canvas(&g.mlx, "MiniRT", 1000, 800) < 0)
		ev_destroy(&g);

	srand(141337);
	mlx_hook(g.mlx.win, STATIC_DESTROY, 0L, ev_destroy, &g);
	mlx_key_hook(g.mlx.win, ev_keypressed, &g);
	mlx_loop_hook(g.mlx.mlx, draw, &g);
	mlx_loop(g.mlx.mlx);
	return (0);
}

