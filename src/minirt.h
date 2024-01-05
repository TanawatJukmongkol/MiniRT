/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:30:53 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/05 10:41:38 by Tanawat J.       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/math.h"
#include "../include/graphics.h"
#include "../include/static_def.h"
#include "../include/world.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_glob
{
	t_mlx		mlx;
	t_world		world;
	t_hittable	hit_record;
	int			render_mode;
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

// MLX weak linking (Apple)
int	ft_loop_end(t_glob *g);
int	ft_destroy_display(t_glob *g);

// Event hooks
int	ev_destroy(t_glob *g);
int ev_keypressed(int keycode, t_glob *g);

