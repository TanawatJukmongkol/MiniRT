/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_check_other.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:28:25 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/12 05:22:37 by tsirirak         ###   ########.fr       */
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
	if (check_symbol(line) == 0 || str_digit(line) == 0)
	{
		return (0);
	}
	else if (line[0] == '-')
	{
		return (check_float_minus(line));
	}
	return (check_floattwo(line));
}

int	str_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_digit_or_symbol(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
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
