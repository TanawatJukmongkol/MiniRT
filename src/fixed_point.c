
#include "minirt.h"

t_fixed_pt double_to_fixed(double num)
{
	return (round(num * (1L << FIXED_BIT_FRAC)));
}

double fixed_to_double(t_fixed_pt num)
{
	return (round((double)num / (1L << FIXED_BIT_FRAC)));
}

t_fixed_pt	fixed_mult(t_fixed_pt a, t_fixed_pt b)
{
	return (double_to_fixed(fixed_to_double(a) * fixed_to_double(b)));
}

