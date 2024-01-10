/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:36:57 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/10 16:37:00 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#ifndef __APPLE__

int	ft_destroy_display(t_glob *g)
{
	return (mlx_destroy_display(g->mlx.mlx));
}

#else

int	ft_destroy_display(t_glob *g)
{
	(void)g;
	return (0);
}

#endif