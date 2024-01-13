/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_other.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:28:25 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/13 23:45:52 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
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

double	decimal(const char *str, double num)
{
	double	dot;

	dot = 0.1;
	while (*str && *str >= '0' && *str <= '9')
	{
		num += (dot * (*str - '0'));
		dot /= 10;
		str++;
	}
	return (num);
}

double	ft_atof(const char *str)
{
	double	num;
	double	n;

	if (str == NULL)
		return (0);
	num = 0;
	n = 1;
	if (str == NULL)
		return (0);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (*str++ == '.')
		num = decimal(str, num);
	return (num * n);
}
