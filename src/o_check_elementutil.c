/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_check_elementutil.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:28:25 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/12 12:48:02 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_element_l(char *line, int num_pl)
{
	char	**str;
	int		i;
	int		re;

	(void) num_pl;
	i = 0;
	re = 1;
	str = ft_split_space(line);
	while (str[i])
		i++;
	if (i >= 3 && str[3] != NULL)
	{
		if (is_space(str[3][0]) != 1)
			re = 0;
	}
	if (check_spiltxyz(str[0]) == 0)
		re = 0;
	else if ((ft_atof(str[1]) < 0 || ft_atof(str[1]) > 1)
		|| check_float(str[1]) == 0)
		re = 0;
	else if (check_spiltrgb(str[2]) == 0)
		re = 0;
	remove_split(str);
	return (re);
}
