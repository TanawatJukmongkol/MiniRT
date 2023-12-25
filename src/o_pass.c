/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_pass.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:29:43 by tjukmong          #+#    #+#             */
/*   Updated: 2023/12/25 22:36:47 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	pass_element(char **argv, t_world *world)
{
	int fd;
	char *line;

	fd = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	world->obj_count = world->ele.pl + world->ele.sp + world->ele.cy + 1;
	world->objs = (t_object *)malloc(sizeof(t_object) * world->obj_count);
	while (line)
	{
		if (check_comment(line) == 0)
			add_element(line, world);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return;
}

void add_element(char *line, t_world *world)
{
	// int i = 0;
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
		add_element_pl(line, world);
	}
	else if (ft_strncmp(line, "sp", 2) == 0)
	{
		line = line + 2;
		add_element_sp(line, world);
	}
	else if (ft_strncmp(line, "cy", 2) == 0)
	{
		line = line + 2;
		add_element_cy(line, world);
	}
}

void add_element_a(char *line, t_world *world)//0-1
{
	char **split;
	char **rgb;
	(void)world;

	split = ft_split(line, ' ');
	world->amb_brightness = double_to_fixed(ft_atof(split[0]));

	rgb = ft_split(split[1], ',');
	world->ambient.r = double_to_fixed(ft_atof(rgb[0]));
	world->ambient.g = double_to_fixed(ft_atof(rgb[1]));
	world->ambient.b = double_to_fixed(ft_atof(rgb[2]));
}

void add_element_c(char *line, t_world *world)//1only
{
	char **split;
	char **xyz;
	(void)world;

	split = ft_split(line, ' ');
	xyz = ft_split(split[0], ',');
	world->cam.pos.x = double_to_fixed(ft_atof(xyz[0]));
	world->cam.pos.y = double_to_fixed(ft_atof(xyz[1]));
	world->cam.pos.z = double_to_fixed(ft_atof(xyz[2]));

	xyz = ft_split(split[1], ',');
	world->cam.normal.x = double_to_fixed(ft_atof(xyz[0]));
	world->cam.normal.y = double_to_fixed(ft_atof(xyz[1]));
	world->cam.normal.z = double_to_fixed(ft_atof(xyz[2]));

	world->cam.fov = double_to_fixed(ft_atof(split[2]));
}
void add_element_sp(char *line, t_world *world)//>=1
{
	char **split;
	char **xyz;
	(void)world;

	split = ft_split(line, ' ');
	xyz = ft_split(split[0], ',');

	world->

}
void add_element_pl(char *line, t_world *world)//>=1
{
	char **split;
	char **rgb;
	(void)world;

	split = ft_split(line, ' ');
	world->amb_brightness = double_to_fixed(ft_atof(split[0]));

	rgb = ft_split(split[1], ',');
	world->ambient.r = double_to_fixed(ft_atof(rgb[0]));
	world->ambient.g = double_to_fixed(ft_atof(rgb[1]));
	world->ambient.b = double_to_fixed(ft_atof(rgb[2]));
}
void add_element_cy(char *line, t_world *world)//>=1
{
	char **split;
	char **rgb;
	(void)world;

	split = ft_split(line, ' ');
	world->amb_brightness = double_to_fixed(ft_atof(split[0]));

	rgb = ft_split(split[1], ',');
	world->ambient.r = double_to_fixed(ft_atof(rgb[0]));
	world->ambient.g = double_to_fixed(ft_atof(rgb[1]));
	world->ambient.b = double_to_fixed(ft_atof(rgb[2]));
}
// void add_element_a(char *line, t_world *world)
// {
// 	char **split;
// 	(void)world;

// 	split = ft_split(line, ' ');
// 	printf("Hello = %s",split[0]);
// }
