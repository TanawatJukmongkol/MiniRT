
#include "minirt.h"

t_fixed_pt double_to_fixed(double num)
{
	return (round(num * (1L << FIXED_BIT_FRAC)));
}

double fixed_to_double(t_fixed_pt num)
{
	return (round((double)num / (1L << FIXED_BIT_FRAC)));
}

