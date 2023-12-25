/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:30:44 by tjukmong          #+#    #+#             */
/*   Updated: 2023/12/22 07:46:35 by Tanawat J.       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Fast Inverse Square Root using fixed point number and Newton's square root method
// The function was explained here: https://www.youtube.com/watch?v=p8u_k2LIZyo
/* t_fixed_pt	q_rsqrt(t_fixed_pt num)
{
	long long	i;
	double		x2;
	double		y;

	x2 = fixed_to_double(num >> 1);
	y = fixed_to_double(num);
	i = *(long long *)&y;
	i = 0x5f3759df - ( i >> 1 );
	y = y * ( 1.5F - (x2 * y * y));
	return (double_to_fixed(*(double *)&y));
} */

void	vec_set(t_vec3 *dst, t_vec3 v)
{
	dst->x = v.x;
	dst->y = v.y;
	dst->z = v.z;
}

t_vec3	vec3(double x, double y, double z)
{
	t_vec3	v;

	v.x = double_to_fixed(x);
	v.y = double_to_fixed(y);
	v.z = double_to_fixed(z);
	return (v);
}

t_vec3	vec3_raw(t_fixed_pt x, t_fixed_pt y, t_fixed_pt z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec3	vec_add(t_vec3 v1, t_vec3 v2)
{
	return (vec3_raw(
				v1.x + v2.x,
				v1.y + v2.y,
				v1.z + v2.z));
}

t_vec3	vec_sub(t_vec3 v1, t_vec3 v2)
{
	return (vec3_raw(
				v1.x - v2.x,
				v1.y - v2.y,
				v1.z - v2.z));
}

t_vec3	vec_mult(t_vec3 v, double num)
{
	t_fixed_pt	fixed_num;

	fixed_num = double_to_fixed(num);
	return (vec3_raw(
				fixed_mult(v.x, fixed_num),
				fixed_mult(v.y, fixed_num),
				fixed_mult(v.z, fixed_num)));
}

t_fixed_pt	vec_dot(t_vec3 v1, t_vec3 v2)
{
	return (fixed_mult(v1.x, v2.x)
			+ fixed_mult(v1.y, v2.y)
			+ fixed_mult(v1.z, v2.z));
}

t_vec3	vec_cross(t_vec3 v1, t_vec3 v2)
{
	return (vec3_raw(
				fixed_mult(v1.y, v2.z) - fixed_mult(v1.z, v2.y),
				fixed_mult(v1.x, v2.z) - fixed_mult(v1.z, v2.x),
				fixed_mult(v1.x, v2.y) - fixed_mult(v1.y, v2.x)));
}

double	vec_mag(t_vec3 vec)
{
	return (sqrt((fixed_to_double(
			fixed_mult(vec.x, vec.x) +
			fixed_mult(vec.y, vec.y) +
			fixed_mult(vec.z, vec.z)
			))));
}

t_vec3	vec_norm(t_vec3 vec)
{
	return (vec_mult(vec, 1 / vec_mag(vec)));
}

// Get point at t.
// P(t) = A + tb
t_vec3	ray_at(t_ray ray, double t)
{
	return (vec_add(ray.origin, vec_mult(ray.direction, t)));
}

