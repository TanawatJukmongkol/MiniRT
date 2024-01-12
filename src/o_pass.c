/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_pass.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:29:43 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/12 12:58:43 by tsirirak         ###   ########.fr       */
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
