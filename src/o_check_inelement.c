/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_check_inelement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:28:25 by tjukmong          #+#    #+#             */
/*   Updated: 2023/12/29 18:33:28 by tsirirak         ###   ########.fr       */
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

int	check_float(char *line)
{
	int	dot;
	int	i;

	dot = 0;
	i = 0;
	if (count_minus(line) >= 2 || count_dot(line) >= 2
		|| line[0] == '.' || line[ft_strlen(line) - 1] == '.')
		return (0);
	else if (line[0] == '-')
	{
		i = 1;
		while (line[i])
		{
			if ((line[i] >= '0' && line[i] <= '9') || line[i] == '.')
				i++;
			else
				return (0);
		}
		if (i <= 1)
			return (0);
		return (1);
	}
	while ((*line >= '0' && *line <= '9') || *line == '.'
		|| *line == '\0' || *line == ' ')
	{
		if (*line == '.')
		{
			dot++;
			if (dot >= 2)
			{
				printf("dot---- \n");
				return (0);
			}
		}
		else if (*line == '\0' || *line == ' ')
			return (i);
		line++;
		i++;
	}
	if (dot == 0)
		return (0);
	return (0);
}

int	check_int(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		i++;
	}
	if (i <= 0)
		return (0);
	else if ((str[i] >= 9 && str[i] <= 13)
		|| str[i] == 32 || str[i] == '\0' || str[i])
	{
		if (i >= 1)
			return (1);
	}
	return (0);
}
