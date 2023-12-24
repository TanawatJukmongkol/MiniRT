/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_pass.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:29:43 by tjukmong          #+#    #+#             */
/*   Updated: 2023/12/23 23:10:50 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	pass_element(char **argv, t_world *world)
{
	int fd;
	char *line;

	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (check_comment(line) == 0)
			add_element(line, world);


		free(line);
		line = get_next_line(fd);
	}
	return;
}

void add_element(char *line, t_world *world)
{
	int i = 0;

	while ((*line >= 9 && *line <= 13) || *line == 32)
		line++;
	if (*line == 'A')
		add_element_a(*line, world);
}

void add_element_a(char *line, t_world world)
{

}
