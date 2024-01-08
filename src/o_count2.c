/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_count2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:28:25 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/08 09:29:01 by Tanawat J.       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	count_dot(char *str)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	while (str[i])
	{
		if (str[i] == '.')
			dot++;
		i++;
	}
	return (dot);
}

int	check_minus(char *str)
{
	int	i;
	int	minus;

	i = 0;
	minus = 0;
	while (str[i])
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	if (minus >= 2)
		return (0);
	i = 1;
	while (str[i])
	{
		if (str[i] == '-')
			return (0);
		i++;
	}
	return (1);
}


int	count_minus(char *str)
{
	int	i;
	int	minus;

	i = 0;
	minus = 0;
	while (str[i])
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	return (minus);
}
