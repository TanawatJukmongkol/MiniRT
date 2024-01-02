/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:30:53 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/02 20:06:50 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include "../include/math.h"
#include "../include/graphics.h"
#include "../include/static_def.h"
#include "../lib/libft/libft.h"
#include "../lib/gnl/get_next_line.h"
// #include <X11/X.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>


typedef struct s_element
{
	int		a;//0-1
	int		c;//1
	int		l;
	int		pl;//>=1
	int		sp;//>=1
	int		cy;//>=1
}				t_element;


enum e_obj
{//enumคล้ายๆกับ define โดยจะเรียงตัวเลขให้เลย
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
	enum e_obj    type;        // Object identification
	t_color        abs_color;    // Color absorptiveness (inverted color) rgb ของ
	t_vec3        pos;        // Position กล้องจุดไหน
	t_vec3        normal;        // Normal vector กล้องหันไปทางไหน
	t_fixed_pt    fov;        // Field of view การทำมุมของกล้อง มุมอง
	t_fixed_pt    size;        // Diameter (or other if have bonus)
	t_fixed_pt    height;        // Height
	t_fixed_pt    brightness;    // Brightness
} t_object;

typedef struct s_world
{
	t_fixed_pt	amb_brightness;	// Ambient light brightness
	t_color		ambient;		// Ambient color
	t_object	cam;			// Camera
	t_object	*objs;			// Object list
	size_t		obj_count;		// Number of ojects
	t_element ele;				//Opal ไว้นับจำนวน element
}	t_world;

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

// MLX weak linking (Apple)
int	ft_loop_end(t_glob *g);
int	ft_destroy_display(t_glob *g);

//check_file
int check_file(int argc, char **argv, t_element *ele);
int check_in_file(int fd, t_element *ele);
int check_element(char *line, t_element *ele);
int checkdot_rt(char *str);
void set_ele(t_element *ele);

//check_element
int check_element_a(char *line, int num_a);
int check_element_c(char *line, int num_c);
// int check_element_l(char *line, int num_l);
int check_element_sp(char *line, int num_sp);
int check_element_pl(char *line, int num_pl);
int check_element_cy(char *line, int num_cy);

//check_inelement
int	check_spiltxyz(char *line);
int	check_spiltxyz_3d(char *line);
int check_spiltrgb(char *line);

//other
int check_comment(char *str);
int count_split(char **str);
double	ft_atof_dot(const char *nptr, double nbr);
double	ft_atof(const char *nptr);
int check_number(char *str);
int count_dot(char *str);
int count_minus(char *str);
int count_comma(char *str);
int count_element(t_element *ele);

//pass
void	pass_element(char **argv, t_world *world);
int	add_element(char *line, int i, t_world *world);
void	add_element_a(char *line, t_world *world);
void	add_element_c(char *line, t_world *world);
void	add_element_pl(char *line, int i, t_world *world);
void	add_element_sp(char *line, int i, t_world *world);
void	add_element_cy(char *line, int i, t_world *world);
void	remove_split(char **sp);
void	remove_split_struct(t_world *w);

//check_other
int check_float(char *line);
int check_int(char *str);
int	check_floattwo(char *line);

#endif
