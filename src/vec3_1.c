/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:30:44 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/10 16:57:27 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
