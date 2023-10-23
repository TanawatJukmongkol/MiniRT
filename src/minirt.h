/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:30:53 by tjukmong          #+#    #+#             */
/*   Updated: 2023/10/23 16:26:07 by Tanawat J.       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../lib/libft/libft.h"
#include "../include/math.h"
#include "../include/graphics.h"
#include <X11/X.h>
#include <math.h>

#define FIXED_BIT_FRAC 8

enum t_obj
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
	enum t_obj	type;
	t_color		color;
	t_vec3		pos;
	t_vec3		normal;
	t_fixed_pt	fov;
	t_fixed_pt	size;
	t_fixed_pt	height;
	t_fixed_pt	brightness;
}				t_object;

typedef struct s_world
{
	t_fixed_pt	amb_brightness;
	t_color		ambient;
	t_object	*objs;
}				t_world;

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

