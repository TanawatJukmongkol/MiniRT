/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_count.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:28:25 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/12 09:56:47 by Tanawat J.       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	count_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
	if (ele->c != 1 || ele->a != 1 || ele->l != 1)
	{
		printf("Error\nInvalid format: %s",
			"more than one capital lettered element. (A, C, L)\n");
		return (0);
	}
	return (1);
}
