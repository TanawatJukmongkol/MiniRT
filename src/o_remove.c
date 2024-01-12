/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_remove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:29:43 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/12 12:57:07 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	remove_split(char **sp)
{
	int	i;

	i = 0;
	while (sp[i] != NULL)
	{
		free(sp[i]);
		i++;
	}
	free(sp);
}

void	remove_split_struct(t_world *w)
{
	if (w->objs != NULL)
	{
		free(w->objs);
		w->objs = NULL;
	}
}
