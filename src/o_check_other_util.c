/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_check_other_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:28:25 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/12 12:55:45 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_number_util(char *str)
{
	if (count_dot(str) >= 2
		|| str[0] == '.' || str[ft_strlen(str) - 1] == '.'
		|| (check_float(str) == 0 && check_int(str) == 0))
		return (0);
	return (1);
}

int	check_number(char *str)
{
	int	i;

	if (check_number_util(str) == 0)
		return (0);
	else if (str[0] == '-')
	{
		i = 1;
		if (check_minus(str) == 0)
			return (0);
		while (str[i])
		{
			if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
				i++;
			else
				return (0);
		}
		if (i <= 1)
			return (0);
		return (1);
	}
	if (check_int(str) == 1)
		return (1);
	else if (check_float(str) != 0)
		return (1);
	return (1);
}

int	checkdot_rt(char *str)
{
	if (ft_strrchr(str, '.') == NULL
		|| ft_strncmp(ft_strrchr(str, '.'), ".rt", 10))
		return (0);
	return (1);
}
