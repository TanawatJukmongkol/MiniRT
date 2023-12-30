/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_other.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:28:25 by tjukmong          #+#    #+#             */
/*   Updated: 2023/12/29 22:46:53 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
