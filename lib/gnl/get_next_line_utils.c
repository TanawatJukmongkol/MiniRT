/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:58:11 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/03 14:21:34 by Tanawat J.       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_vars	*files_fd(int fd)
{
	static t_vars	v[FD_MAX];

	if (fd < 0 || fd > FD_MAX || (v[fd].eof && v[fd].fin))
		return (NULL);
	return (&v[fd]);
}

void	free_gnl(int fd, char *str)
{
	t_vars	*v;
	t_token	*next;

	free(str);
	v = files_fd(fd);
	if (!v)
		return ;
	while (v->t)
	{
		next = (v->t)->next;
		free(v->t);
		v->t = next;
	}
	v->eof = 1;
	v->fin = 1;
	v->t_last = NULL;
	v->tok_len = 0;
}
