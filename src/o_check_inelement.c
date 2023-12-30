/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_check_inelement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:28:25 by tjukmong          #+#    #+#             */
/*   Updated: 2023/12/29 22:18:45 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_spiltxyz(char *line)
{
	char	**xyz;
	int		i;

	i = 0;
	xyz = ft_split(line, ',');
	if (count_comma(line) > 2)
		return (0);
	while (xyz[i])
	{
		if (check_number(xyz[i]) == 0)
		{
			return (0);
		}
		i++;
	}
	if (i == 3)
		return (1);
	return (0);
}

int	check_spiltxyz_3d(char *line)
{
	char	**xyz;
	int		i;

	i = 0;
	xyz = ft_split(line, ',');
	if (count_comma(line) > 2)
		return (0);
	while (xyz[i])
	{
		if (check_number(xyz[i]) == 0)
		{
			return (0);
		}
		else if (ft_atof(xyz[i]) < -1 || ft_atof(xyz[i]) > 1)
		{
			return (0);
		}
		i++;
	}
	if (i == 3)
		return (1);
	return (0);
}

int	check_spiltrgb(char *line)
{
	char	**rgb;
	int		i;

	i = 0;
	if (count_comma(line) >= 3)
		return (0);
	rgb = ft_split(line, ',');
	while (rgb[i])
	{
		if (check_int(rgb[i]) == 0)
		{
			printf("return (0) check_splitrgb\n");
			return (0);
		}
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
		{
			printf("check_0-255\n");
			return (0);
		}
		i++;
	}
	if (i == 3 && check_int(rgb[2]) != 0)
		return (1);
	return (0);
}
