/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:25:35 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/14 15:36:06 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	count_split_space(char *s)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (is_space(s[i]) == 1)
		i++;
	while (s[i])
	{
		if (!is_space(s[i]) && s[i]
			&& (is_space(s[i + 1]) == 1 || s[i + 1] == '\0'))
			c++;
		i++;
	}
	return (c);
}

int	count_word_space(char *str, int start)
{
	int	count;

	count = 0;
	while (is_space(str[start]) != 1 && str[start] != '\0')
	{
		start++;
		count++;
	}
	return (count);
}

char	**ft_split_space(char *s)
{
	char	**str;
	int		count;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	count = count_split_space(s);
	str = malloc(sizeof(char *) * (count + 1));
	while (i < count)
	{
		if (is_space(s[j]))
			j++;
		else
		{
			str[i] = ft_substr(s, j, count_word_space(s, j));
			j = j + count_word_space(s, j);
			i++;
		}
	}
	str[i] = NULL;
	return (str);
}
