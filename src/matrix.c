
#include "minirt.h"

t_vec3	matrx_rotatate_x(t_vec3 v, double theta)
{
	t_fixed_pt	ct;
	t_fixed_pt	st;

	ct = double_to_fixed(cos(theta));
	st = double_to_fixed(sin(theta));
	return (vec3_raw(
		fixed_mult(v.x, 1),
		fixed_mult(v.x, 0),
		fixed_mult(v.x, 0)
	));
}

