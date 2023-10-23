
#ifndef MATH_H
# define MATH_H

typedef long t_fixed_pt;
typedef struct s_vec3
{
	t_fixed_pt	x;
	t_fixed_pt	y;
	t_fixed_pt	z;
}				t_vec3;

// Fixed point number
t_fixed_pt double_to_fixed(double num);
double fixed_to_double(t_fixed_pt num);

#endif
