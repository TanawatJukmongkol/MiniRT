/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_check_element.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:28:25 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/05 02:56:50 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	is_space(char c)
{
	if ((c >= 9 && c <= 13)
		|| c == 32 || c)
		return (1);
	return (0);
}

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
	{
		printf("str[i] = %s\n",str[i]);
		i++;
	}
	printf("i = %c\n",str[2][0]);
	printf("i = %d\n",i);
	if (i == 3 && (ft_isalnum(str[2][0]) != '\0' || str[2][0] == '/'))
		re = 0;
	else if (i > 3)
		re = 0;
	else if ((ft_atof(str[0]) < 0 || ft_atof(str[0]) > 1)
		|| check_float(str[0]) == 0)
		re = 0;
	else if (check_spiltrgb(str[1]) == 0)
	{
		re = 0;
	}
	remove_split(str);
	printf("re = %d\n",re);
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
	while (str[i])
		i++;
	if ((i == 4 && ft_isalnum((str[3][0]) != 0 | str[3][0] == '/')))
		re = 0;
	else if (i > 4)
		re = 0;
	if (check_spiltxyz(str[0]) == 0 || check_spiltxyz_3d(str[1]) == 0)
		re = 0;
	if (check_int(str[2]) == 0 || ft_atoi(str[2]) < 0
		|| ft_atoi(str[2]) > 180)
		re = 0;
	remove_split(str);
	return (re);
}

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
	if ((i == 4 && (ft_isalnum(str[3][0]) != 0 | str[2][0] == '/')))
		re = 0;
	else if (i > 4)
		re = 0;
	if (check_spiltxyz(str[0]) == 0)
		re = 0;
	else if (check_float(str[1]) == 0)
		re = 0;
	else if (check_spiltrgb(str[2]) == 0)
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
	if (i == 4 && (ft_isalnum(str[3][0]) != 0 || str[3][0] == '/'))
		re = 0;
	else if (i < 4)
	if (i > 4)
		re = 0;
	if (check_spiltxyz(str[0]) == 0)
		re = 0;
	else if (check_float(str[1]) == 0)
	{
		re = 0;
	}
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
	if (i == 4 && (ft_isalnum(str[3][0]) != 0 | str[3][0] == '/'))
		re = 0;
	else if (i > 4)
		re = 0;
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
	if (i == 6 && (ft_isalnum(str[5][0]) != 0 | str[2][0] == '/'))
		re = 0;
	else if (i > 6)
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
