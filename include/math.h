
#ifndef MATH_H
# define MATH_H

# ifndef FIXED_BIT_FRAC
#  define FIXED_BIT_FRAC 18
# endif

# include <math.h>

# define PI		3.141592653
# define TAU		6.283185307
# define HALF_PI	1.570796326
# define ONE_RAD	0.017453292
# define PI_FIX	double_to_fixed(PI)
# define TAU_FIX	double_to_fixed(TAU)
# define HPI_FIX	double_to_fixed(HALF_PI)

typedef long long	t_fixed_pt;
typedef union u_vec3
{
	struct
	{
		t_fixed_pt	x;
		t_fixed_pt	y;
		t_fixed_pt	z;
	};
	t_fixed_pt		v[3];
}	t_vec3;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}				t_ray;

// Fixed point number
t_fixed_pt	double_to_fixed(double num);
double		fixed_to_double(t_fixed_pt num);

t_fixed_pt	fixed_mult(t_fixed_pt a, t_fixed_pt b);

// Vectors
t_vec3		vec3(double x, double y, double z);
t_vec3		vec3_raw(t_fixed_pt x, t_fixed_pt y, t_fixed_pt z);
void		vec_set(t_vec3 *dst, t_vec3 v);
t_vec3		vec_add(t_vec3 v1, t_vec3 v2);
t_vec3		vec_sub(t_vec3 v1, t_vec3 v2);
t_vec3		vec_mult(t_vec3 v, double num);
t_fixed_pt	vec_dot(t_vec3 v1, t_vec3 v2);
t_vec3		vec_cross(t_vec3 v1, t_vec3 v2);
double		vec_mag(t_vec3);
t_vec3		vec_norm(t_vec3 v);
double		vec_norm_theta(t_vec3 v, t_vec3 norm);
int			vec_assert_equal(t_vec3 v1, t_vec3 v2);

// Rays
t_vec3		ray_at(t_ray ray, double t);

#endif

