/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_len.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:28:25 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/12 02:24:17 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int len_dot(char *str, char c) {
	int i = 0;
	int len = 0;

	while (str[i]) {
		if (str[i] == c)
			len++;
		i++;
	}
	return len;
}


int len_size(char **str) {
	int i = 0;

	while (str[i] != NULL)
		i++;
	return (i);
}

int len_xyz(char *str) {
	char **sp;
	int	len;

	len = 0;

	sp = NULL;
	sp = ft_split(str, ',');
	while(sp[len]) {
		free(sp[len]);
		len++;
	}
	free(sp);
	return (len);
}
