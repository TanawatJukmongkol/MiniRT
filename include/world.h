
#ifndef WORLD_H
# define WORLD_H

# include "graphics.h"
# include "math.h"
# include <unistd.h>

enum e_obj
{
	// pos, normal, FOV
	camera,
	// pos, brightness, color
	point_light,
	// pos, size (diameter), color
	sphere,
	// pos, normal, color
	plane_infinite,
	// pos, size (diameter), height
	cylinder
};

typedef struct s_object
{
	enum e_obj	type;		// Object identification
	t_color		abs_color;	// Color absorptiveness (inverted color)
	t_vec3		pos;		// Position
	t_vec3		normal;		// Normal vector
	t_fixed_pt	fov;		// Field of view
	t_fixed_pt	size;		// Diameter (or other if have bonus)
	t_fixed_pt	height;		// Height
	t_fixed_pt	brightness;	// Brightness
}				t_object;

typedef struct s_hittable
{
	t_vec3	norm;
	t_color	color;
	double	intensity;
	double	t;
	int		n;
}				t_hittable;

typedef struct s_element
{
	int		a;//0-1
	int		c;//1
	int		l;
	int		pl;//>=1
	int		sp;//>=1
	int		cy;//>=1
}				t_element;

typedef struct s_world
{
	t_fixed_pt	amb_brightness;	// Ambient light brightness
	t_color		ambient;		// Ambient color
	t_object	cam;			// Camera
	t_object	*objs;			// Object list
	size_t		obj_count;		// Number of ojects
	t_object	*lights;		// Light list
	size_t		light_count;	// Number of lights
	t_hittable	hit_rec;
	t_element	ele;
}				t_world;

// Hittables (object)
void	hittable(t_world *w, t_hittable *rec, t_ray r);
void	hit_sphere(t_hittable *rec, t_object obj, t_ray r);

// Lighting
void	lighting(t_world *w, t_hittable *rec, t_ray r);

#endif

