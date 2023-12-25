/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:30:53 by tjukmong          #+#    #+#             */
/*   Updated: 2023/12/25 04:40:45 by Tanawat J.       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/math.h"
#include "../include/graphics.h"
#include "../include/static_def.h"
#include "../include/hittable.h"
// #include <X11/X.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_world
{
	t_fixed_pt	amb_brightness;	// Ambient light brightness
	t_color		ambient;		// Ambient color
	t_object	cam;			// Camera
	t_object	*objs;			// Object list
	size_t		obj_count;		// Number of ojects
	t_hittable	hit_rec;
}				t_world;

typedef struct s_glob
{
	t_mlx		mlx;
	t_world		world;
}				t_glob;

/*  Z ^
 *    |  Y
 *    |/
 *    |---> X
*/

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

// MLX weak linking (Apple)
int	ft_loop_end(t_glob *g);
int	ft_destroy_display(t_glob *g);
