/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:30:44 by tjukmong          #+#    #+#             */
/*   Updated: 2023/11/24 14:24:04 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Fast Inverse Square Root using fixed point number and Newton's square root method
// The function was explained here: https://www.youtube.com/watch?v=p8u_k2LIZyo
t_fixed_pt	q_rsqrt(t_fixed_pt num)
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
}

void	vec_set(t_vec3 *dst, t_vec3 v)
{
	dst->x = v.x;
	dst->y = v.y;
	dst->z = v.z;
}

t_vec3	vec3(double x, double y, double z)
{
	static t_vec3	v;

	v.x = double_to_fixed(x);
	v.y = double_to_fixed(y);
	v.z = double_to_fixed(z);
	return (v);
}

t_vec3	vec_add(t_vec3 v1, t_vec3 v2)
{
	static t_vec3	v;

	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	v.z = v1.z + v2.z;
	return (v);
}

t_vec3	vec_sub(t_vec3 v1, t_vec3 v2)
{
	static t_vec3	v;

	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	v.z = v1.z - v2.z;
	return (v);
}

t_vec3	vec_mult(t_vec3 v, double num)
{
	static t_vec3	prod;

	prod.x = double_to_fixed(fixed_to_double(v.x) * num);
	prod.y = double_to_fixed(fixed_to_double(v.y) * num);
	prod.z = double_to_fixed(fixed_to_double(v.z) * num);
	return (prod);
}

t_fixed_pt	vec_dot(t_vec3 v1, t_vec3 v2)
{
	double	prod;

	prod  = 0.0;
	prod += fixed_to_double(v1.x) * fixed_to_double(v2.x);
	prod += fixed_to_double(v1.y) * fixed_to_double(v2.y);
	prod += fixed_to_double(v1.z) * fixed_to_double(v2.z);
	return (double_to_fixed(prod));
}

t_vec3	vec_cross(t_vec3 v1, t_vec3 v2)
{
	static t_vec3	v;

	v.x = fixed_mult(v1.y, v2.z) - fixed_mult(v1.z, v2.y);
	v.y = fixed_mult(v1.x, v2.z) - fixed_mult(v1.z, v2.x);
	v.z = fixed_mult(v1.x, v2.y) - fixed_mult(v1.y, v2.x);
	return (v);
}

t_vec3	vec_norm(t_vec3 vec)
{
	double			x;
	double			y;
	double			z;
	double			m;

	x = fixed_to_double(vec.x);
	y = fixed_to_double(vec.y);
	z = fixed_to_double(vec.z);
	m = sqrt((x * x) + (y * y) + (z * z));
	return (vec3(x/m, y/m, z/m));
}

// Get point at t.
// P(t) = A + tb
t_vec3	ray_at(t_ray ray, double t)
{
	return vec_add(ray.origin, vec_cross(
				vec3(t, t, t), ray.direction)); 
}

