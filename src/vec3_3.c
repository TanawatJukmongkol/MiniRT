/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:58:05 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/10 16:58:11 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vec_norm_theta(t_vec3 v, t_vec3 norm)
{
	double	nomina;
	double	denom;

	nomina = fixed_to_double(vec_dot(v, norm));
	denom = vec_mag(v) * vec_mag(norm);
	return (acos(floor(nomina * 10000 / denom) / 10000));
}

int	vec_assert_equal(t_vec3 v1, t_vec3 v2)
{
	return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z);
}

// Get point at t.
// P(t) = A + tb
t_vec3	ray_at(t_ray ray, double t)
{
	return (vec_add(ray.origin, vec_mult(ray.direction, t)));
}
