/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:40:57 by Tanawat J.        #+#    #+#             */
/*   Updated: 2024/01/10 16:54:44 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	hit_sphere(t_hittable *rec, t_object obj, t_ray r)
{
	t_vec3		oc;
	t_fixed_pt	sq[2];
	t_fixed_pt	discrim;
	double		t;

	obj.size = fixed_mult(obj.size, double_to_fixed(0.5));
	vec_set(&oc, vec_sub(r.origin, obj.pos));
	sq[0] = fixed_mult(vec_dot(oc, r.direction), double_to_fixed(2));
	sq[1] = vec_dot(oc, oc) - fixed_mult(obj.size, obj.size);
	discrim = fixed_mult(sq[0], sq[0]) - fixed_mult(double_to_fixed(4), sq[1]);
	if (discrim < 0)
		return ;
	t = (-fixed_to_double(sq[0]) - sqrtf(fixed_to_double(discrim))) / 2.0;
	if (t > 0 && (rec->t > t || rec->t == -1))
	{
		rec->t = t;
		set_color(&rec->color, obj.abs_color);
		vec_set(&rec->norm, vec_norm(vec_sub(ray_at(r, t), obj.pos)));
	}
}

double	hit_plane_eq(t_hittable *rec, t_object obj, t_ray r)
{
	t_vec3	oc;
	double	denom;
	double	t;

	vec_set(&oc, vec_sub(r.origin, obj.pos));
	denom = fixed_to_double(vec_dot(vec_mult(obj.normal, -1.0), r.direction));
	if (denom < 10e-6)
		return (-1);
	t = fixed_to_double(vec_dot(oc, obj.normal)) / denom;
	if (t > 0 && (rec->t > t || rec->t == -1))
		return (t);
	return (-1);
}

void	hit_plane_infinite(t_hittable *rec, t_object obj, t_ray r)
{
	double	t;

	t = hit_plane_eq(rec, obj, r);
	if (t > 1)
	{
		rec->t = t;
		set_color(&rec->color, obj.abs_color);
		vec_set(&rec->norm, obj.normal);
	}
}

void	hittable(t_world *w, t_hittable *rec, t_ray r)
{
	size_t	i;

	i = 0;
	while (i < w->obj_count)
	{
		if (w->objs[i].type == sphere)
			hit_sphere(rec, w->objs[i], r);
		if (w->objs[i].type == plane_infinite)
			hit_plane_infinite(rec, w->objs[i], r);
		if (w->objs[i].type == cylinder)
			hit_cylinder(rec, w->objs[i], r);
		i++;
	}
}
