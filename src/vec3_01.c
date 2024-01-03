/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:30:44 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/02 23:12:31 by Tanawat J.       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Fast Inverse Square Root using fixed point number and Newton's square root method
// The function was explained here: https://www.youtube.com/watch?v=p8u_k2LIZyo
/*t_fixed_pt	q_rsqrt(t_fixed_pt num)
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
}*/

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

t_fixed_pt	vec_dot(t_vec3 v1, t_vec3 v2)
{
	static t_fixed_pt	prod;

	prod += fixed_mult(v1.x, v2.x);
	prod += fixed_mult(v1.y, v2.y);
	prod += fixed_mult(v1.z, v2.z);
	return (prod);
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
	static t_vec3	v;
	double			m;

	m = sqrt(fixed_to_double(
			fixed_mult(vec.x, vec.x) +
			fixed_mult(vec.y, vec.y) +
			fixed_mult(vec.x, vec.z)));
	v.x /= m;
	v.y /= m;
	v.z /= m;
	return (v);
}

// Get point at t.
// P(t) = A + tb
t_vec3	ray_at(t_ray ray, double t)
{
	return vec_add(ray.origin, vec_cross(
				vec3(t, t, t), ray.direction)); 
}

