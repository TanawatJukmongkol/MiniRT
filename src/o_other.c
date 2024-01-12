/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_other.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:28:25 by tjukmong          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/01/12 12:55:42 by tsirirak         ###   ########.fr       */
=======
<<<<<<< HEAD
/*   Updated: 2024/01/11 19:50:05 by tsirirak         ###   ########.fr       */
=======
/*   Updated: 2024/01/10 14:40:02 by Tanawat J.       ###   ########.fr       */
>>>>>>> merge-final
>>>>>>> 0624114a53171464102e3a49b613790c977bf3d9
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
	if ((c >= 9 && c <= 13)
		|| c == 32)
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
