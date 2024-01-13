/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_validate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:28:25 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/12 05:49:29 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_symbol(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && i == 0)
			len++;
		else if ((str[i] == '+' || str[i] == '.' ) && i == 0)
			len += 2;
		else if ((str[i] == '-' || str[i] == '+') && i != 0)
			return (0);
		else if (str[i] == '.' && (i == ((int)ft_strlen(str) - 1)))
			return (0);
		i++;
	}
	if (len > 1)
		return (0);
	return (1);
}

int	check_symbol(char *line)
{
	if (check_minus(line) == 0 || count_dot(line) >= 2
		|| line[0] == '.' || line[ft_strlen(line) - 1] == '.')
		return (0);
	return (1);
}

int	validate_int(char *num)
{
	char	**str;
	int		i;
	int		ret;

	str = NULL;
	i = 0;
	ret = 1;
	str = ft_split(num, ',');
	while (str[i])
	{
		if (validate_not_digit_or_symbol(str[i]) == 0)
			ret = 0;
		if (validate_symbol(str[i]) == 0)
			ret = 0;
		if (len_dot(str[i], '.') > 1)
			ret = 0;
		i++;
	}
	remove_split(str);
	return (ret);
}

int	validate_not_digit_or_symbol(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (!is_digit_or_symbol(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_digit_or_symbol(int c)
{
	if (ft_isdigit(c) || c == '-' || c == '+' || c == '.')
		return (1);
	return (0);
}
