/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:30:53 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/12 13:24:06 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../include/math.h"
# include "../include/graphics.h"
# include "../include/static_def.h"
# include "../include/world.h"
# include "../lib/libft/libft.h"
# include "../lib/gnl/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_glob
{
	t_mlx		mlx;
	t_world		world;
	t_hittable	hit_record;
	int			render_mode;
}				t_glob;

// MLX weak linking (Apple)
int		ft_loop_end(t_glob *g);
int		ft_destroy_display(t_glob *g);

// Event hooks
int		ev_destroy(t_glob *g);
int		draw(t_glob *g);
int		hooks(t_glob *g);

// Camera
void	fragment_renderer(t_glob *g, int chunk_nbr, t_color frag(
				t_world *world, t_ray ray, t_hittable *rec));
t_color	fragment(t_world *w, t_ray r, t_hittable *rec);

// Shapes
void	hit_sphere(t_hittable *rec, t_object obj, t_ray r);
double	hit_plane_eq(t_hittable *rec, t_object obj, t_ray r);
void	hit_plane_infinite(t_hittable *rec, t_object obj, t_ray r);
void	hit_cylinder(t_hittable *rec, t_object obj, t_ray r);

//check_file
int		check_file(int argc, char **argv, t_element *ele);
int		check_in_file(int fd, t_element *ele);
int		check_element(char *line, t_element *ele);
int		checkdot_rt(char *str);
void	set_ele(t_element *ele);

//check_element
int		check_element_a(char *line, int num_a);
int		check_element_c(char *line, int num_c);
int		check_element_l(char *line, int num_l);
int		check_element_sp(char *line, int num_sp);
int		check_element_pl(char *line, int num_pl);
int		check_element_cy(char *line, int num_cy);

//check_inelement
int		check_spiltxyz(char *line);
int		check_spiltxyz_3d(char *line);
int		check_spiltrgb(char *line);
int		check_splitrgb2(char *line);

//other
int		check_comment(char *str);
int		count_split(char **str);
double	ft_atof_dot(const char *nptr, double nbr);
double	ft_atof(const char *nptr);
int		check_number(char *str);
int		count_dot(char *str);
int		count_minus(char *str);
int		count_comma(char *str);
int		count_element(t_element *ele);
int		check_minus(char *str);

//pass
void	pass_element(char **argv, t_world *world);
void	add_element(char *line, t_world *world);
void	add_element_a(char *line, t_world *world);
void	add_element_c(char *line, t_world *world);
void	add_element_l(char *line, int i, t_world *world);
void	add_element_pl(char *line, int i, t_world *world);
void	add_element_sp(char *line, int i, t_world *world);
void	add_element_cy(char *line, int i, t_world *world);
void	remove_split(char **sp);
void	remove_split_struct(t_world *w);

//check_other
int		check_float(char *line);
int		check_int(char *str);
int		check_floattwo(char *line);

//validate
int		validate_not_digit_or_symbol(char *str);
int		validate_int(char *num);
int		validate_symbol(char *str);
int		is_digit_or_symbol(int c);

//len
int		len_dot(char *str, char c);
int		len_size(char **str);
int		len_xyz(char *str);

//
int		str_digit(char *str);
int		check_floattwo(char *line);
int		check_float_minus(char *line);
int		check_symbol(char *line);
void	add_element_cytwo(char **sp, int i, t_world *world);
int		is_space(char c);
#endif
