/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_check_other.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:28:25 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/14 15:31:27 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if ((str[i] >= 9 && str[i] <= 13)
		|| str[i] == 32 || str[i] == '\0')
	{
		if (i >= 1)
			return (1);
	}
	return (0);
}

int	check_float(char *line)
{
	if (count_len_number(line) == 0)
		return (0);
	if (check_symbol(line) == 0 || str_digit(line) == 0)
		return (0);
	if (line[0] == '-')
		return (check_float_minus(line));
	return (check_floattwo(line));
}

int	check_floattwo(char *line)//0.2
{
	int	dot;

	dot = 0;
	while (ft_isdigit(*line) == 1 || *line == '.'
		|| *line == '\0' || *line == ' ')
	{
		if (*line == '.')
		{
			dot++;
			if (dot >= 2)
				return (0);
		}
		line++;
	}
	return (1);
}

int	check_float_minus(char *line)
{
	int	i;

	i = 1;
	if (ft_strlen(line) == 1)
		return (0);
	while (line[i])
	{
		if (line[1] == '0' && line[2] == '\0')
		{
			return (0);
		}
		else if (ft_isdigit(line[i]) == 1 || line[i] == '.')
		{
			i++;
		}
		else
			return (0);
	}
	return (1);
}

int	check_comment(char *str)
{
	int	i;

	i = 0;
	while (str[i] || str[i] == '\n')
	{
		if (str[i] == '#')
			return (1);
		i++;
	}
	return (0);
}
