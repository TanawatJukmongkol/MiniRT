/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:29:43 by tjukmong          #+#    #+#             */
/*   Updated: 2023/11/23 04:42:30 by Tanawat J.       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	get_pixel_dirr(t_glob *g, int x, int y)
{
	double	focal = 1;
	double	vh = 2;
	double	vw = vh * g->mlx.aspect_ratio;
	double	frac_w = 1.0 / g->mlx.width;
	double	frac_h = 1.0 / g->mlx.height;
	t_vec3	u;
	t_vec3	v;
	t_vec3	du;
	t_vec3	dv;
	t_vec3	upper_left;
	t_vec3	uv0;

	vec_set(&u, vec3(vw, 0, 0));
	vec_set(&v, vec3(0, -vh, 0));
	vec_set(&du, vec_cross(u, vec3(frac_w, frac_w, frac_w)));
	vec_set(&dv, vec_cross(v, vec3(frac_h, frac_h, frac_h)));
	vec_set(&upper_left,
		vec_sub (
			vec_sub(
				vec_sub(g->world.cam.pos, vec3(0, 0, focal)),
				vec_cross(u, vec3(0.5, 0.5, 0.5))
			),
			vec_cross(u, vec3(0.5, 0.5, 0.5))
		)
	);
	vec_set(&uv0,
		vec_add (upper_left,
			vec_cross(
				vec_add(du, dv),
				vec3(0.5, 0.5, 0.5)
			)
		)
	);
	return vec_sub(
		vec_add (
			uv0, vec_add(
				vec_cross(du, vec3(x,x,x)),
				vec_cross(dv, vec3(y,y,y))
			)
		),
		g->world.cam.pos
	);
}

void	fragment_renderer(t_glob *g, int chunk_nbr, t_color frag(t_mlx *ctx, t_world *world, t_ray ray))
{
	int 	x;
	int 	y;
	int 	h;
	t_ray	r;

	h = g->mlx.height >> 5;
	y = h * chunk_nbr;
	h += y;
	while (++y < h)
	{
		x = 0;
		while (x < g->mlx.width)
		{
			vec_set(&r.origin, vec3(0, 0, 0));
			vec_set(&r.direction, get_pixel_dirr(g, x, y));
			putpixel(&g->mlx, x, y, frag(&g->mlx,
						&g->world, r));
			x++;
		}
		y++;
	}
}

t_color	fragment(t_mlx *ctx, t_world *w, t_ray r)
{
	t_color	c_light;
	(void)ctx;
	(void)w;
	(void)r;
	// t_color	c_obj;
	/*
	(void)w;
	set_color(&c_light, rgb(255, 255, 255));

	set_color(&c_obj, rgb(
		cos((float)r.origin.x / ctx->width * PI) * 255 * ((float)r.origin.y / ctx->height),
		sin((float)r.origin.x / ctx->width * PI) * 255 * ((float)r.origin.y / ctx->height),
		cos((float)r.origin.x / ctx->width * PI + PI) * 255 * ((float)r.origin.y / ctx->height)
	));
	color_invrt(&c_obj);
	color_sub(&c_light, c_obj);

	color_mult_norm(&c_light, 0.8 + ((float)rand() / RAND_MAX) / 42);
	*/

	printf("%f\n", fixed_to_double(r.direction.y));
	set_color(&c_light, rgb(
		fixed_to_double(vec_norm(r.direction).y) * 255,
		0,
		0)
	);
	// printf("%x", rgb_to_hex(c_light));
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
	mlx_loop_end(g->mlx.mlx);
	if (g->mlx.canvas.ptr)
		mlx_destroy_image(g->mlx.mlx, g->mlx.canvas.ptr);
	if (g->mlx.win)
		mlx_destroy_window(g->mlx.mlx, g->mlx.win);
	mlx_destroy_display(g->mlx.mlx);
	free(g->mlx.mlx);
	exit(0);
	return (0);
}

int ev_keypressed(int keycode, t_glob *g)
{
	if (keycode == XK_Escape)
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
	mlx_hook(g.mlx.win, DestroyNotify, 0L, ev_destroy, &g);
	mlx_key_hook(g.mlx.win, ev_keypressed, &g);
	mlx_loop_hook(g.mlx.mlx, draw, &g);
	mlx_loop(g.mlx.mlx);
	return (0);
}

