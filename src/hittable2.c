/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:16:04 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/10 16:52:28 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	hit_cap(t_hittable *rec, t_object obj, t_ray r, int up)
{
	t_vec3	v;
	double	t;

	if (!up)
		vec_set(&obj.normal, vec_mult(obj.normal, -1));
	vec_set(&obj.pos,
		vec_add(obj.pos, vec_mult(obj.normal, fixed_to_double(obj.height))));
	t = hit_plane_eq(rec, obj, r);
	if (t == -1)
		return (0);
	vec_set(&v, vec_sub(ray_at(r, t), obj.pos));
	if (sqrt(fixed_to_double(vec_dot(v, v))) <= fixed_to_double(obj.size))
	{
		rec->t = t;
		set_color(&rec->color, obj.abs_color);
		vec_set(&rec->norm, obj.normal);
	}
	return (1);
}

void	init_cylinder(t_hittable *rec, t_object *obj, t_ray r)
{
	obj->size = fixed_mult(obj->size, double_to_fixed(0.5));
	obj->height = fixed_mult(obj->height, double_to_fixed(0.5));
	if (!hit_cap(rec, *obj, r, 1))
		hit_cap(rec, *obj, r, 0);
}

void	hit_cylinder_eq(t_object obj, t_ray r, t_vec3 oc, t_fixed_pt *sq)
{
	vec_set(&oc, vec_sub(r.origin, obj.pos));
	sq[0] = vec_dot(r.direction, r.direction) - fixed_mult(
			vec_dot(r.direction, obj.normal), vec_dot(r.direction, obj.normal));
	sq[1] = fixed_mult(vec_dot(r.direction, oc) - fixed_mult(vec_dot(\
		r.direction, obj.normal), vec_dot(oc, obj.normal)), double_to_fixed(2));
	sq[2] = vec_dot(oc, oc) - fixed_mult(vec_dot(oc, obj.normal),
			vec_dot(oc, obj.normal)) - fixed_mult(obj.size, obj.size);
}

void	hit_cylinder(t_hittable *rec, t_object obj, t_ray r)
{
	t_vec3		oc;
	t_fixed_pt	sq[3];
	t_fixed_pt	discrim;
	double		t;
	double		m;

	init_cylinder(rec, &obj, r);
	vec_set(&oc, vec_sub(r.origin, obj.pos));
	hit_cylinder_eq(obj, r, oc, sq);
	discrim = fixed_mult(sq[1], sq[1]) - fixed_mult(double_to_fixed(4),
			fixed_mult(sq[0], sq[2]));
	if (discrim < 0)
		return ;
	t = (-fixed_to_double(sq[1]) - sqrt(
				fixed_to_double(discrim))) / (2.0 * fixed_to_double(sq[0]));
	m = fixed_to_double(vec_dot(r.direction,
				vec_mult(obj.normal, t)) + vec_dot(oc, obj.normal));
	if (t > 0 && (rec->t > t || rec->t == -1)
		&& m < fixed_to_double(obj.height) && m > -fixed_to_double(obj.height))
	{
		rec->t = t;
		set_color(&rec->color, obj.abs_color);
		vec_set(&rec->norm, vec_norm(vec_sub(vec_sub(
						ray_at(r, t), obj.pos), vec_mult(obj.normal, m))));
	}
}
