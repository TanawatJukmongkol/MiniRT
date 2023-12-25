/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_check_element.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:28:25 by tjukmong          #+#    #+#             */
/*   Updated: 2023/12/25 13:33:57 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int check_element_a(char *line, int num_a)
{
	(void) num_a;
	char **str;
	int i = 0;

	str = ft_split_space(line);
	while (str[i])
		i++;

	if ((i == 3 && ft_isalnum(str[2][0]) != 0))
		return (0);
	else if (i > 3)
		return (0);
	else if ((ft_atof(str[0]) < 0 || ft_atof(str[0]) > 1) || check_float(str[0]) == 0)
		return (0);
	else if (check_spiltrgb(str[1]) == 0)
		return (0);
	return (1);
}
int check_element_c(char *line, int num_c)
{
	(void) num_c;
	char **str;
	int i = 0;

	str = ft_split_space(line);
	while (str[i])
		i++;
	if ((i == 4 && ft_isalnum(str[3][0]) != 0))
		return (0);
	else if (i > 4)
		return (0);
	if (check_spiltxyz(str[0]) == 0)
		return (0);
	else if (check_spiltxyz_3d(str[1]) == 0)
		return (0);
	else if (check_int(str[2]) == 0 || ft_atoi(str[2]) < 0 || ft_atoi(str[2]) > 180)
		return (0);
	return (1);

}

// int check_element_l(char *line, int num_l)
// {
// 	(void) num_l;
// 	char **str;
// 	int i = 0;

// 	str = ft_split_space(line);
// 	printf("l\n");
// 	while (str[i])
// 		i++;
// 	if ((i == 3 && ft_isalnum(str[2][0]) != 0))
// 		return (0);
// 	else if (i > 3)
// 		return (0);
// 	else if (check_spiltxyz(str[0]) == 0)
// 		return (0);
// 	else if ((ft_atof(str[1]) < 0 || ft_atof(str[1]) > 1) || check_float(str[1]) == 0)
// 		return (0);
// 	else if (check_spiltrgb(str[2]) == 0)
// 		return (0);
// 	return (1);
// }

int check_element_sp(char *line, int num_sp)
{
	(void) num_sp;
	char **str;
	int i = 0;

	str = ft_split_space(line);
	while (str[i])
		i++;
	if ((i == 4 && ft_isalnum(str[3][0]) != 0))
		return (0);
	else if (i > 4)
		return (0);
	else if (check_spiltxyz(str[0]) == 0)
		return (0);
	else if (check_float(str[1]) == 0)
		return (0);
	else if (check_spiltrgb(str[2]) == 0)
		return (0);
	return (1);
}

int check_element_pl(char *line, int num_pl)
{
	(void) num_pl;
	char **str;
	int i = 0;

	str = ft_split_space(line);
	while (str[i])
		i++;
	if ((i == 4 && ft_isalnum(str[3][0]) != 0))
		return (0);
	else if (i > 4)
		return (0);
	else if (check_spiltxyz(str[0]) == 0)
		return (0);
	else if (check_spiltxyz_3d(str[1]) == 0)
		return (0);
	else if (check_spiltrgb(str[2]) == 0)
		return (0);
	return (1);
}

int check_element_cy(char *line, int num_cy)
{
	(void) num_cy;
	char **str;
	int i = 0;

	str = ft_split_space(line);
	while (str[i])
		i++;
	if ((i == 6 && ft_isalnum(str[5][0]) != 0))
		return (0);
	else if (i > 6)
		return (0);
	else if (check_spiltxyz(str[0]) == 0)
		return (0);
	else if (check_spiltxyz_3d(str[1]) == 0)
		return (0);
	else if (check_float(str[2]) == 0)
		return (0);
	else if (check_float(str[3]) == 0)
		return (0);
	else if (check_spiltrgb(str[4]) == 0)
		return (0);
	return (1);
}



int count_element(t_element *ele)
{
	if (ele->c != 1 || ele->a >= 2)
		return (0);
	if (ele->pl == 0 || ele->sp == 0 || ele->cy == 0)
		return (0);
	// if (ele.l != 1)
		// return (0);
	return (1);
}
