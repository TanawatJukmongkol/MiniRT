/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:29:43 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/12 14:22:35 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	draw(t_glob *g)
{
	if (g->mlx.frame >= 4)
		g->mlx.frame = 0;
	fragment_renderer(g, g->mlx.frame % 4, fragment);
	g->mlx.frame++;
	return (update_canvas(&g->mlx));
}

int	validate_normal(t_world *world)
{
	size_t	i;
	int		ret;

	i = 0;
	ret = 0;
	while (i < world->obj_count)
	{
		if (world->objs[i].type == camera
			|| world->objs[i].type == plane_infinite
			|| world->objs[i].type == cylinder)
		{
			if (round(vec_mag(world->objs[i].normal) * 100) / 100 != 1)
			{
				ret = 1;
				printf("Error\nNormal of type #%d %s",
					world->objs[i].type,
					"not using a unit vector. (magnitude does not equal 1)\n");
			}
		}
		i++;
	}
	return (ret);
}

int	validate_cam(t_world *world)
{
	int	ret;

	ret = 0;
	if (round(vec_mag(world->cam.normal) * 100) / 100 != 1)
	{
		ret = 1;
		printf("Error\nNormal not a unit vector.");
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	t_glob		g;

	(void)argc;
	set_ele(&g.world.ele);
	if (!check_file(argc, argv, &g.world.ele))
		return (1);
	pass_element(argv, &g.world);
	if (validate_normal(&g.world) == 1 || validate_cam(&g.world) == 1)
		return (free(g.world.objs), free(g.world.lights), 1);
	if (init_canvas(&g.mlx, "MiniRT", 1000, 800) < 0)
		ev_destroy(&g);
	srand(141337);
	return (hooks(&g));
}
