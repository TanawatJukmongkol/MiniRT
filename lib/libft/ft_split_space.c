/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:25:35 by tjukmong          #+#    #+#             */
/*   Updated: 2023/12/11 22:35:53 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int	ft_leen_space(char *s, int check)
{
    int len_i;
	int j;

	len_i = 0;
    while (*s)
	{
        while (*s == ' ' || *s == '\t')
			s++;
        if (*s && *s != ' ' && *s != '\t')
		{
            len_i++;
			j = 0;
			while (s[j] && s[j] != ' ' && s[j] != '\t')
				j++;
			if (check == 2)
				return j;
			s += j;
        }
    }
    return len_i;
}

char **ft_split_space(char *s)
{
    char **str;
    int j;
	int i = 0;
	int len = ft_leen_space(s, 1);
	int k;

    if (!(str = malloc(sizeof(char *) * (len + 1))))
		return (NULL);
    while (i < len)
	{
        while (*s == ' ' || *s == '\t')
			s++;
        j = ft_leen_space(s, 2);
        if (!(str[i] = malloc(sizeof(char) * (j + 1))))
			return (NULL);
		k = 0;
		while (k < j)
		{
			str[i][k] = s[k];
			k++;
		}
        str[i][k] = '\0';
        s += j;
        i++;
    }
    str[i] = NULL;
    return str;
}



// int	ft_leen_space(char *s, int check)
// {
// 	int	len_i;
// 	int	j;

// 	len_i = 0;
// 	while (*s != '\0')
// 	{
// 		while (*s == ' ' || *s == '\t')
// 			s++;
// 		if (*s != ' ' && *s != '\t' && *s != '\0')
// 		{
// 			len_i++;
// 			j = 0;
// 			while (*s != ' ' && *s != '\t' && *s != '\0')
// 			{
// 				j++;
// 				s++;
// 			}
// 		}
// 		if (check == 2)
// 			return (j);
// 	}
// 	return (len_i);
// }

// char	**ft_split_space(char *s)
// {
// 	char	**str;
// 	int		j;
// 	int		i_str;
// 	int		len_i;
// 	int		count;

// 	len_i = ft_leen_space(s, 1);
// 	str = malloc(sizeof(char *) * (len_i + 1));
// 	if (str == NULL)
// 		return (NULL);
// 	i_str = 0;
// 	while (i_str < len_i)
// 	{
// 		j = ft_leen_space(s, 2);
// 		str[i_str] = ft_calloc(sizeof(char), (j + 1));
// 		while (*s == ' ' && *s == '\t' && *s)
// 			s++;
// 		count = 0;
// 		while (j > count)
// 			str[i_str][count++] = *s++;
// 		i_str++;
// 	}
// 	str[i_str] = NULL;
// 	return (str);
// }
