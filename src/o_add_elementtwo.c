/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_add_elementtwo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:29:43 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/12 13:01:59 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	add_element_cytwo(split, i, world);
	remove_split(split);
}

void	add_element_cytwo(char **sp, int i, t_world *world)
{
	char	**abs;

	abs = ft_split(sp[4], ',');
	world->objs[i].abs_color.r = double_to_fixed(ft_atof(abs[0]));
	world->objs[i].abs_color.g = double_to_fixed(ft_atof(abs[1]));
	world->objs[i].abs_color.b = double_to_fixed(ft_atof(abs[2]));
	remove_split(abs);
}
