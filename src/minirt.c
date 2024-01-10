/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:29:43 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/10 16:51:38 by tjukmong         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_glob		g;

	(void)argc;
	set_ele(&g.world.ele);
	if (!check_file(argc, argv, &g.world.ele))
		return (1);
	pass_element(argv, &g.world);
	if (init_canvas(&g.mlx, "MiniRT", 1000, 800))
		return (ev_destroy(&g));
	srand(141337);
	return (hooks(&g));
}
