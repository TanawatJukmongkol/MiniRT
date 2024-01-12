/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:38:01 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/10 16:38:02 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	matrx_rotatate_x(t_vec3 v, double theta)
{
	t_fixed_pt	ct;
	t_fixed_pt	st;

	ct = double_to_fixed(cos(theta * (PI / 180)));
	st = double_to_fixed(sin(theta * (PI / 180)));
	return (vec3_raw(
			fixed_mult(v.x, 1) + fixed_mult(v.y, 0) + fixed_mult(v.z, 0),
			fixed_mult(v.x, 0) + fixed_mult(v.y, ct) + fixed_mult(v.z, -st),
			fixed_mult(v.x, 0) + fixed_mult(v.y, st) + fixed_mult(v.z, ct)
		));
}

t_vec3	matrx_rotatate_y(t_vec3 v, double theta)
{
	t_fixed_pt	ct;
	t_fixed_pt	st;

	ct = double_to_fixed(cos(theta * (PI / 180)));
	st = double_to_fixed(sin(theta * (PI / 180)));
	return (vec3_raw(
			fixed_mult(v.x, ct) + fixed_mult(v.y, 0) + fixed_mult(v.z, st),
			fixed_mult(v.x, 0) + fixed_mult(v.y, 1) + fixed_mult(v.z, 0),
			fixed_mult(v.x, -st) + fixed_mult(v.y, 0) + fixed_mult(v.z, ct)
		));
}

t_vec3	matrx_rotatate_z(t_vec3 v, double theta)
{
	t_fixed_pt	ct;
	t_fixed_pt	st;

	ct = double_to_fixed(cos(theta * (PI / 180)));
	st = double_to_fixed(sin(theta * (PI / 180)));
	return (vec3_raw(
			fixed_mult(v.x, ct) + fixed_mult(v.y, -st) + fixed_mult(v.z, 0),
			fixed_mult(v.x, st) + fixed_mult(v.y, ct) + fixed_mult(v.z, 0),
			fixed_mult(v.x, 0) + fixed_mult(v.y, 0) + fixed_mult(v.z, 1)
		));
}
