/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_check_element.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:28:25 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/13 23:29:12 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_element_a(char *line, int num_a)
{
	char	**str;
	int		i;
	int		re;

	(void) num_a;
	i = 0;
	re = 1;
	str = ft_split_space(line);
	while (str[i])
		i++;
	if (i >= 2 && str[2] != NULL)
	{
		if (is_space(str[2][0]) != 1)
			re = 0;
	}
	else if ((ft_atof(str[0]) < 0 || ft_atof(str[0]) > 1)
		|| check_float(str[0]) == 0)
		re = 0;
	else if (check_spiltrgb(str[1]) == 0)
		re = 0;
	remove_split(str);
	return (re);
}

int	check_element_c(char *line, int num_c)
{
	char	**str;
	int		i;
	int		re;

	(void) num_c;
	i = 0;
	re = 1;
	str = ft_split_space(line);
	if (i > 3)
		re = 0;
	if (check_spiltxyz(str[0]) == 0)
		re = 0;
	else if (check_spiltxyz_3d(str[1]) == 0)
		re = 0;
	else if (check_number(str[2]) == 0)
		re = 0;
	else if (ft_atoi(str[2]) < 0 || ft_atoi(str[2]) > 180)
		re = 0;
	remove_split(str);
	return (re);
}

int	check_element_sp(char *line, int num_sp)
{
	char	**str;
	int		i;
	int		re;

	(void) num_sp;
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
	else if (check_float(str[1]) == 0)
		re = 0;
	else if (check_spiltrgb(str[2]) == 0)
		re = 0;
	remove_split(str);
	return (re);
}

int	check_element_pl(char *line, int num_pl)
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
	else if (check_spiltxyz(str[0]) == 0)
		re = 0;
	else if (check_spiltxyz_3d(str[1]) == 0)
		re = 0;
	else if (check_spiltrgb(str[2]) == 0)
		re = 0;
	remove_split(str);
	return (re);
}

int	check_element_cy(char *line, int num_cy)
{
	char	**str;
	int		i;
	int		re;

	(void) num_cy;
	i = 0;
	re = 1;
	str = ft_split_space(line);
	while (str[i])
		i++;
	if (i >= 5 && str[5] != NULL && is_space(str[5][0]) != 1)
		re = 0;
	if (check_spiltxyz(str[0]) == 0)
		re = 0;
	else if (check_spiltxyz_3d(str[1]) == 0)
		re = 0;
	else if (check_float(str[2]) == 0)
		re = 0;
	else if (check_float(str[3]) == 0)
		re = 0;
	else if (check_spiltrgb(str[4]) == 0)
		re = 0;
	remove_split(str);
	return (re);
}
