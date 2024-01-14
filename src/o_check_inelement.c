/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_check_inelement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:28:25 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/14 15:31:52 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_spiltxyz(char *line)
{
	char	**xyz;
	int		i;

	i = 0;
	xyz = NULL;
	if (count_comma(line) != 2)
		return (0);
	xyz = ft_split(line, ',');
	if (len_size(xyz) != 3)
		return (0);
	while (xyz[i])
	{
		if (check_number(xyz[i]) == 0)
		{
			remove_split(xyz);
			return (0);
		}
		i++;
	}
	remove_split(xyz);
	if (i == 3)
		return (1);
	return (0);
}

int	check_spiltxyz_3d(char *line)
{
	char	**xyz;
	int		i;

	i = 0;
	xyz = NULL;
	if (count_comma(line) > 2)
		return (0);
	xyz = ft_split(line, ',');
	while (xyz[i])
	{
		if (check_number(xyz[i]) == 0)
			return (remove_split(xyz), 0);
		else if (ft_atof(xyz[i]) < -1 || ft_atof(xyz[i]) > 1)
			return (remove_split(xyz), 0);
		i++;
	}
	remove_split(xyz);
	if (i == 3)
		return (1);
	return (0);
}

int	check_splitrgb2(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] < '0' || line[i] > '9')
		{
			if ((line[i] >= 9 && line[i] <= 13)
				|| line[i] == 32 || line[i] == '\0')
			{
				if (i >= 1)
					return (1);
			}
			else if (line[i] != ',')
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_spiltrgb(char *line)
{
	char	**rgb;
	int		i;

	i = 0;
	if (count_comma(line) >= 3 || check_splitrgb2(line) == 0)
		return (0);
	rgb = ft_split(line, ',');
	while (rgb[i])
	{
		if (check_int(rgb[i]) == 0)
			return (remove_split(rgb), 0);
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
			return (remove_split(rgb), 0);
		i++;
	}
	if (i == 3 && check_int(rgb[2]) != 0)
	{
		remove_split(rgb);
		return (1);
	}
	return (0);
}
