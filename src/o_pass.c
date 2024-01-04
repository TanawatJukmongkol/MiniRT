/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_pass.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:29:43 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/04 18:42:21 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	pass_element(char **argv, t_world *world)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	world->obj_count = world->ele.pl + world->ele.sp + world->ele.cy + 1;
	world->objs = (t_object *)malloc(sizeof(t_object) * world->obj_count);
	while (line)
	{
		if (check_comment(line) == 0)
			i = i + add_element(line, i, world);
		free(line);
		line = get_next_line(fd);
	}
	remove_split_struct(world);
	close(fd);
}

int	add_element(char *line, int i, t_world *world)
{
	while ((*line >= 9 && *line <= 13) || *line == 32)
		line++;
	if (*line == 'A')
	{
		line++;
		add_element_a(line, world);
	}
	else if (*line == 'C')
	{
		line++;
		add_element_c(line, world);
	}
	else if (ft_strncmp(line, "pl", 2) == 0)
	{
		line = line + 2;
		add_element_pl(line, i, world);
		i++;
	}
	else if (ft_strncmp(line, "sp", 2) == 0)
	{
		line = line + 2;
		add_element_sp(line, i, world);
		i++;
	}
	else if (ft_strncmp(line, "cy", 2) == 0)
	{
		line = line + 2;
		add_element_cy(line, i, world);
		i++;
	}
	return (i);
}

void	add_element_a(char *line, t_world *world)
{
	char	**split;
	char	**rgb;

	split = ft_split(line, ' ');
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

	split = ft_split(line, ' ');
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

void	add_element_sp(char *line, int i, t_world *world)
{
	char	**split;
	char	**xyz;
	char	**abs;

	split = ft_split(line, ' ');
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

	split = ft_split(line, ' ');
	xyz = ft_split(split[0], ',');
	normal = ft_split(split[1], ',');
	abs = ft_split(split[2], ',');
	world->objs[i].type = point_light;
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
	char	**abs;

	split = ft_split(line, ' ');
	xyz = ft_split(split[0], ',');
	normal = ft_split(split[1], ',');
	abs = ft_split(split[4], ',');
	world->objs[i].type = cylinder;
	world->objs[i].pos.x = double_to_fixed(ft_atof(xyz[0]));
	world->objs[i].pos.y = double_to_fixed(ft_atof(xyz[1]));
	world->objs[i].pos.z = double_to_fixed(ft_atof(xyz[2]));
	remove_split(xyz);
	world->objs[i].normal.x = double_to_fixed(ft_atof(normal[0]));
	world->objs[i].normal.y = double_to_fixed(ft_atof(normal[1]));
	world->objs[i].normal.z = double_to_fixed(ft_atof(normal[2]));
	remove_split(normal);
	world->objs[i].size = double_to_fixed(ft_atof(split[2]));
	world->objs[i].height = double_to_fixed(ft_atof(split[3]));
	world->objs[i].abs_color.r = double_to_fixed(ft_atof(abs[0]));
	world->objs[i].abs_color.g = double_to_fixed(ft_atof(abs[1]));
	world->objs[i].abs_color.b = double_to_fixed(ft_atof(abs[2]));
	remove_split(abs);
	remove_split(split);
}

void	remove_split(char **sp)
{
	int	i;

	i = 0;
	// if (sp == NULL)
	// 	return ;
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
