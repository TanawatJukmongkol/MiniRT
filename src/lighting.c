
#include "minirt.h"

void	l_point_light(t_world *w, t_hittable *rec, t_object light, t_ray r)
{
	t_ray		light_ray;
	t_hittable	light_rec;
	double		theta;
	double		brightness;

	light_rec.t = -1;
	light_ray.origin = ray_at(r, rec->t);
	light_ray.direction = vec_norm(vec_sub(light.pos, light_ray.origin));
	light_ray.origin = light_ray.origin;
	theta = vec_norm_theta(light_ray.direction, rec->norm);

	hittable(w, &light_rec, light_ray);

	brightness = 0;
	if (theta < HALF_PI && (light_rec.t == -1 || vec_mag(vec_sub(light.pos, light_ray.origin)) < light_rec.t))
		brightness = fixed_to_double(light.brightness) * (1.0 - (theta / HALF_PI));
	rec->intensity -= 1 - brightness;
	// No color
	//set_color(&rec->color, color_mult_norm(light.abs_color, brightness));
	// Inverted color
	//set_color(&rec->color, color_sub(rec->color, color_mult_norm(light.abs_color, brightness)));
	// Multi color 
	set_color(&rec->color, color_sub(rec->color, color_mult_norm(color_invrt(light.abs_color), brightness)));
}

void	lighting(t_world *w, t_hittable *rec, t_ray r)
{
	size_t	i;

	i = 0;
	while (i < w->light_count)
	{
		if (w->lights[i].type == point_light)
			l_point_light(w, rec, w->lights[i], r);
		i++;
	}
}

