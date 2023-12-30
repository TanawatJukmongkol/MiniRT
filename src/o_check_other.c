/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_check_other.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:28:25 by tjukmong          #+#    #+#             */
/*   Updated: 2023/12/29 22:47:29 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

int	check_float(char *line)
{
	int	i;

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
	i = check_floattwo(line);
	return (i);
}

int	check_floattwo(char *line)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
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
	return (0);
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


int	check_number(char *str)
{
	int	i;

	i = 0;
	if (count_minus(str) >= 2 || count_dot(str) >= 2
		|| str[0] == '.' || str[ft_strlen(str) - 1] == '.')
		return (0);
	else if (str[0] == '-')
	{
		i = 1;
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
	else if (check_int(str) == 1 || check_float(str) == 1)
		return (1);
	return (1);
}
