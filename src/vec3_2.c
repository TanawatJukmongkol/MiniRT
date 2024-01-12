/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:57:09 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/10 16:57:44 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
					fixed_mult(vec.x, vec.x)
					+ fixed_mult(vec.y, vec.y)
					+ fixed_mult(vec.z, vec.z)
				))));
}

t_vec3	vec_norm(t_vec3 vec)
{
	return (vec_mult(vec, 1 / vec_mag(vec)));
}
