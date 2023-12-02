/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:25:35 by tjukmong          #+#    #+#             */
/*   Updated: 2023/11/28 14:02:41 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int	ft_leen_space(char *s, int check)
{
	int	len_i;
	int	j;

	len_i = 0;
	while (*s != '\0')
	{
		while (*s == ' ' || *s == '\t')
			s++;
		if (*s != ' ' && *s != '\t' && *s != '\0')
		{
			len_i++;
			j = 0;
			while (*s != ' ' && *s != '\t' && *s != '\0')
			{
				j++;
				s++;
			}
		}
		if (check == 2)
			return (j);
	}
	return (len_i);
}

char	**ft_split_space(char *s)
{
	char	**str;
	int		j;
	int		i_str;
	int		len_i;
	int		count;

	len_i = ft_leen_space(s, 1);
	str = malloc(sizeof(char *) * (len_i + 1));
	if (str == NULL)
		return (NULL);
	i_str = 0;
	while (i_str < len_i)
	{
		j = ft_leen_space(s, 2);
		str[i_str] = ft_calloc(sizeof(char), (j + 1));
		while (*s == ' ' && *s == '\t' && *s)
			s++;
		count = 0;
		while (j > count)
			str[i_str][count++] = *s++;
		i_str++;
	}
	str[i_str] = NULL;
	return (str);
}
