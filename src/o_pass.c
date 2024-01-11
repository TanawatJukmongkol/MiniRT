/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_pass.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:29:43 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/12 05:42:51 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	pass_element(char **argv, t_world *world)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	world->obj_count = world->ele.pl + world->ele.sp + world->ele.cy;
	world->light_count = world->ele.l;
	world->objs = malloc(sizeof(t_object) * world->obj_count);
	world->lights = malloc(sizeof(t_object) * world->light_count);
	world->obj_count = 0;
	world->light_count = 0;
	while (line)
	{
		if (check_comment(line) == 0)
			add_element(line, world);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	add_element(char *line, t_world *world)
{
	while ((*line >= '\t' && *line <= '\r') || *line == ' ')
		line++;
	if (*line == 'A')
		add_element_a(++line, world);
	else if (*line == 'C')
		add_element_c(++line, world);
	else if (*line == 'L')
		add_element_l(++line, world->light_count++, world);
	else if (ft_strncmp(line, "pl", 2) == 0)
		add_element_pl(line + 2, world->obj_count++, world);
	else if (ft_strncmp(line, "sp", 2) == 0)
		add_element_sp(line + 2, world->obj_count++, world);
	else if (ft_strncmp(line, "cy", 2) == 0)
		add_element_cy(line + 2, world->obj_count++, world);
}

void	add_element_a(char *line, t_world *world)
{
	char	**split;
	char	**rgb;

	split = ft_split_space(line);
	world->amb_brightness = double_to_fixed(ft_atof(split[0]));
	rgb = ft_split(split[1], ',');
	world->ambient.r = double_to_fixed(ft_atof(rgb[0]));
	world->ambient.g = double_to_fixed(ft_atof(rgb[1]));
	world->ambient.b = double_to_fixed(ft_atof(rgb[2]));
	remove_split(rgb);
	remove_split(split);
}

void	add_element_c(char *line, t_world *world)
{
	char	**split;
	char	**xyz;

	split = ft_split_space(line);
	xyz = ft_split(split[0], ',');
	world->cam.pos.x = double_to_fixed(ft_atof(xyz[0]));
	world->cam.pos.y = double_to_fixed(ft_atof(xyz[1]));
	world->cam.pos.z = double_to_fixed(ft_atof(xyz[2]));
	remove_split(xyz);
	xyz = ft_split(split[1], ',');
	world->cam.normal.x = double_to_fixed(ft_atof(xyz[0]));
	world->cam.normal.y = double_to_fixed(ft_atof(xyz[1]));
	world->cam.normal.z = double_to_fixed(ft_atof(xyz[2]));
	world->cam.fov = double_to_fixed(ft_atof(split[2]));
	remove_split(xyz);
	remove_split(split);
}

void	add_element_l(char *line, int i, t_world *world)
{
	char	**split;
	char	**xyz;
	char	**abs;

	split = ft_split_space(line);
	xyz = ft_split(split[0], ',');
	abs = ft_split(split[2], ',');
	world->lights[i].type = point_light;
	world->lights[i].pos.x = double_to_fixed(ft_atof(xyz[0]));
	world->lights[i].pos.y = double_to_fixed(ft_atof(xyz[1]));
	world->lights[i].pos.z = double_to_fixed(ft_atof(xyz[2]));
	remove_split(xyz);
	world->lights[i].brightness = double_to_fixed(ft_atof(split[1]));
	world->lights[i].abs_color.r = double_to_fixed(ft_atof(abs[0]));
	world->lights[i].abs_color.g = double_to_fixed(ft_atof(abs[1]));
	world->lights[i].abs_color.b = double_to_fixed(ft_atof(abs[2]));
	remove_split(abs);
	remove_split(split);
}

void	add_element_sp(char *line, int i, t_world *world)
{
	char	**split;
	char	**xyz;
	char	**abs;

	split = ft_split_space(line);
	xyz = ft_split(split[0], ',');
	abs = ft_split(split[2], ',');
	world->objs[i].type = sphere;
	world->objs[i].pos.x = double_to_fixed(ft_atof(xyz[0]));
	world->objs[i].pos.y = double_to_fixed(ft_atof(xyz[1]));
	world->objs[i].pos.z = double_to_fixed(ft_atof(xyz[2]));
	remove_split(xyz);
	world->objs[i].size = double_to_fixed(ft_atof(split[1]));
	world->objs[i].abs_color.r = double_to_fixed(ft_atof(abs[0]));
	world->objs[i].abs_color.g = double_to_fixed(ft_atof(abs[1]));
	world->objs[i].abs_color.b = double_to_fixed(ft_atof(abs[2]));
	remove_split(abs);
	remove_split(split);
}

void	add_element_pl(char *line, int i, t_world *world)
{
	char	**split;
	char	**xyz;
	char	**normal;
	char	**abs;

	split = ft_split_space(line);
	xyz = ft_split(split[0], ',');
	normal = ft_split(split[1], ',');
	abs = ft_split(split[2], ',');
	world->objs[i].type = plane_infinite;
	world->objs[i].pos.x = double_to_fixed(ft_atof(xyz[0]));
	world->objs[i].pos.y = double_to_fixed(ft_atof(xyz[1]));
	world->objs[i].pos.z = double_to_fixed(ft_atof(xyz[2]));
	remove_split(xyz);
	world->objs[i].normal.x = double_to_fixed(ft_atof(normal[0]));
	world->objs[i].normal.y = double_to_fixed(ft_atof(normal[1]));
	world->objs[i].normal.z = double_to_fixed(ft_atof(normal[2]));
	remove_split(normal);
	world->objs[i].abs_color.r = double_to_fixed(ft_atof(abs[0]));
	world->objs[i].abs_color.g = double_to_fixed(ft_atof(abs[1]));
	world->objs[i].abs_color.b = double_to_fixed(ft_atof(abs[2]));
	remove_split(abs);
	remove_split(split);
}

void	add_element_cy(char *line, int i, t_world *world)
{
	char	**split;
	char	**xyz;
	char	**normal;

	split = ft_split_space(line);
	xyz = ft_split(split[0], ',');
	normal = ft_split(split[1], ',');
	world->objs[i].type = cylinder;
	world->objs[i].pos.x = double_to_fixed(ft_atof(xyz[0]));
	world->objs[i].pos.y = double_to_fixed(ft_atof(xyz[1]));
	world->objs[i].pos.z = double_to_fixed(ft_atof(xyz[2]));
	remove_split(xyz);
	world->objs[i].normal.x = double_to_fixed(ft_atof(normal[0]));
	world->objs[i].normal.y = double_to_fixed(ft_atof(normal[1]));
	world->objs[i].normal.z = double_to_fixed(ft_atof(normal[2]));
	world->objs[i].normal = vec_norm(world->objs[i].normal);
	remove_split(normal);
	world->objs[i].size = double_to_fixed(ft_atof(split[2]));
	world->objs[i].height = double_to_fixed(ft_atof(split[3]));
	add_element_cytwo(line, i, world);
	remove_split(split);
}

void	add_element_cytwo(char *line, int i, t_world *world)
{
	char	**abs;

	abs = ft_split(line, ',');
	world->objs[i].abs_color.r = double_to_fixed(ft_atof(abs[0]));
	world->objs[i].abs_color.g = double_to_fixed(ft_atof(abs[1]));
	world->objs[i].abs_color.b = double_to_fixed(ft_atof(abs[2]));
	remove_split(abs);
}

void	remove_split(char **sp)
{
	int	i;

	i = 0;
	while (sp[i] != NULL)
	{
		free(sp[i]);
		i++;
	}
	free(sp);
}

void	remove_split_struct(t_world *w)
{
	if (w->objs != NULL)
	{
		free(w->objs);
		w->objs = NULL;
	}
}
