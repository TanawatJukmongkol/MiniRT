/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:30:53 by tjukmong          #+#    #+#             */
/*   Updated: 2023/11/22 20:24:31 by Tanawat J.       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../lib/libft/libft.h"
#include "../include/math.h"
#include "../include/graphics.h"
#include <X11/X.h>
#include <math.h>

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
	t_fixed_pt	fov;		// Field of view
	t_fixed_pt	size;		// Diameter (or other if have bonus)
	t_fixed_pt	height;		// Height
	t_fixed_pt	brightness;	// Brightness
}				t_object;

typedef struct s_world
{
	t_fixed_pt	amb_brightness;	// Ambient light brightness
	t_color		ambient;		// Ambient color
	t_object	cam;			// Camera
	t_object	*objs;			// Object list
	size_t		obj_count;		// Number of ojects
}				t_world;

typedef struct s_glob
{
	t_mlx	mlx;
	t_world	world;
}				t_glob;

/*
	t_world
		|- amb_brightness
		|- ambient
		|- obj -> {
			t_shape {type: camera, pos: t_vec3 {x,y,z}, normal: t_vec3{x,y,z}, fov: t_fixed_pt},
			t_shape {type: point_ligh, pos: t_vec3 {x,y,z}, size: t_fixed_pt, color: t_color},
			...,
			NULL
		}
*/

/*
	GRAPHICAL PIPELINE
	[File parsing] -< RGBA to OkLAB >-> [Render] -< OkLAB to Hex >-> [ Draw ]
*/

