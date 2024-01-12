/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:23:21 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/10 16:59:14 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	get_pixel_dirr(t_glob *g, int x, int y)
{
	double	vw;
	double	vh;
	t_vec3	dirr;
	t_vec3	u;
	t_vec3	v;

	vw = tanf(fixed_to_double(g->world.cam.fov) * ONE_RAD * 0.5);
	vh = vw / g->mlx.aspect_ratio;
	vec_set(&u, vec_add(u, g->world.cam.normal));
	vec_set(&u, vec_cross(g->world.cam.normal, vec3(0, -1, 0)));
	vec_set(&v, vec_cross(u, g->world.cam.normal));
	vec_set(&u, vec_mult(u, (((float)x / g->mlx.width) - 0.5) * vw));
	vec_set(&v,
		vec_mult(v, ((((float)g->mlx.height - y) / g->mlx.height) - 0.5) * vh));
	vec_set(&dirr, vec_norm(vec_add(g->world.cam.normal, vec_add(u, v))));
	return (dirr);
}

/*
t_vec3	get_pixel_dirr(t_glob *g, int x, int y)
{
	double	focal = 1;
	double	vw = tanf(fixed_to_double(g->world.cam.fov) * ONE_RAD * 0.5) * focal;
	double	vh = vw / g->mlx.aspect_ratio;
	t_vec3	dirr;
	t_vec3	u;
	t_vec3	v;

	vec_set(&u, vec_add(
		u, vec_mult(g->world.cam.normal, focal))); // Add focus vector
	vec_set(&u, vec_cross(
		g->world.cam.normal, vec3(0, -1, 0))); // alignment vec x up vector
	vec_set(&v, vec_cross(u, g->world.cam.normal)); // u x look_at

	// Set u, v to length of half viewport width, height modified by x, y.
	vec_set(&u, vec_mult(u, (((float)x / g->mlx.width) - 0.5) * vw));
	vec_set(&v, vec_mult(
		v, ((((float)g->mlx.height - y) / g->mlx.height) - 0.5) * vh));

	vec_set(&dirr, vec_norm(vec_add(
				vec_mult(g->world.cam.normal, focal),
				vec_add(u, v))));

	// printf("< %f, %f, %f >\n",
	fixed_to_double(dirr.x), fixed_to_double(dirr.y), fixed_to_double(dirr.z));
	return dirr;
}
*/

void	fragment_renderer(
	t_glob *g, int chunk_nbr, t_color frag(
		t_world *world, t_ray ray, t_hittable *rec))
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
			putpixel(&g->mlx, x, y,
				frag(&g->world, r, &g->hit_record));
			x++;
		}
		y++;
	}
}

t_color	fragment(t_world *w, t_ray r, t_hittable *rec)
{
	t_color		c_light;

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
