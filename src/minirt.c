/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:29:43 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/02 23:14:06 by Tanawat J.       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


int main(int argc, char **argv)
{
	t_glob glob;
	(void)argc;

	set_ele(&glob.world.ele);
	if (check_file(argc, argv, &glob.world.ele) == 0)
		return (0);
	pass_element(argv, &glob.world);
	return (1);
}

// int	main(void)
// {
// 	t_glob	g;

// 	if (init_canvas(&g.mlx, "MiniRT", 1000, 800) < 0)
// 		ev_destroy(&g);

// 	vec_set(&g.world.cam.pos, vec3(0, 0, 0));//

// 	srand(141337);
// 	mlx_hook(g.mlx.win, STATIC_DESTROY, 0L, ev_destroy, &g);
// 	mlx_key_hook(g.mlx.win, ev_keypressed, &g);
// 	// mlx_loop_hook(g.mlx.mlx, draw, &g);
// 	mlx_loop(g.mlx.mlx);
// 	return (0);
// }
