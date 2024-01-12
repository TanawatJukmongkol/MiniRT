/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:37:08 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/10 16:37:09 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#ifndef __APPLE__

int	ft_loop_end(t_glob *g)
{
	return (mlx_loop_end(g->mlx.mlx));
}

#else

int	ft_loop_end(t_glob *g)
{
	(void)g;
	return (0);
}

#endif