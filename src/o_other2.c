/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_other2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:28:25 by tjukmong          #+#    #+#             */
/*   Updated: 2023/12/28 03:01:00 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

int	check_float_minus(char *line)
{
	int	i;

	i = 0;
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

	num = 0;
	n = 1;
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

// double	ft_atof(const char *nptr)
// {
// 	double	nbr;
// 	double	sign;

// 	nbr = 0;
// 	sign = 1;
// 	while (*nptr == ' ' || (*nptr >= '\a' && *nptr <= '\r'))
// 		nptr++;
// 	if (*nptr == '-')
// 	{
// 		sign = -1;
// 		nptr++;
// 	}
// 	else if (*nptr == '+')
// 		nptr++;
// 	while (*nptr)
// 	{
// 		if (*nptr >= '0' && *nptr <= '9')
// 			nbr = (nbr * 10) + (*nptr - '0');
// 		else
// 			break ;
// 		nptr++;
// 	}
// 	if (*nptr == '.')
// 	{
// 		nptr++;
// 		nbr = ft_atof_dot(nptr, nbr);
// 	}
// 	return (sign * nbr);
// }
