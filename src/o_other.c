/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_other.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:28:25 by tjukmong          #+#    #+#             */
/*   Updated: 2023/12/29 18:48:12 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

int	count_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

double	ft_atof_dot(const char *nptr, double nbr)
{
	double	dot;

	dot = 0.1;
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		nbr = nbr + dot * (*nptr - '0');
		dot = dot / 10;
		nptr++;
	}
	return (nbr);
}

double	ft_atof(const char *nptr)
{
	double	nbr;
	double	sign;

	nbr = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= '\a' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr)
	{
		if (*nptr >= '0' && *nptr <= '9')
			nbr = (nbr * 10) + (*nptr - '0');
		else
			break ;
		nptr++;
	}
	if (*nptr == '.')
	{
		nptr++;
		nbr = ft_atof_dot(nptr, nbr);
	}
	return (sign * nbr);
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
		{
			return (0);
		}
		return (1);
	}
	else if (check_int(str) == 1 || check_float(str) == 1)
	{
		return (1);
	}
	return (1);
}

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

int	count_comma(char *str)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (str[i])
	{
		if (str[i] == ',')
			comma++;
		i++;
	}
	return (comma);
}

int	count_element(t_element *ele)
{
	if (ele->c != 1 || ele->a >= 2)
		return (0);
	if (ele->pl == 0 || ele->sp == 0 || ele->cy == 0)
		return (0);
	return (1);
}
