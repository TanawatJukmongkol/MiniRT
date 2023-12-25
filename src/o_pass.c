/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_pass.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:29:43 by tjukmong          #+#    #+#             */
/*   Updated: 2023/12/25 11:32:11 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	pass_element(char **argv, t_world *world)
{
	int fd;
	char *line;

	printf("pass element fd : %s\n", argv[1]);
	fd = 0;
	fd = open(argv[1], O_RDONLY);
	printf("fd : %d\n", fd);
	// exit(0);

	line = get_next_line(fd);
	printf("line : %s\n", line);
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
}

void add_element_a(char *line, t_world *world)
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

void add_element_c(char *line, t_world *world)
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
void add_element_pl(char *line, t_world *world)
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
void add_element_sp(char *line, t_world *world)
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
void add_element_cy(char *line, t_world *world)
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
