/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:42:45 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/03 14:20:56 by Tanawat J.       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_next(t_vars *v)
{
	if (!v->t)
	{
		v->t = malloc(sizeof(t_token));
		v->t->next = NULL;
		v->t->nbyte = 0;
		v->t_last = v->t;
	}
	else if (!v->eof)
	{
		v->t_last->next = malloc(sizeof(t_token));
		v->t_last = v->t_last->next;
		v->t_last->next = NULL;
		v->t_last->nbyte = 0;
	}
	else
		return ;
	v->tok_len++;
	v->t_last->nbyte = read(v->fd, v->t_last->buff, BUFFER_SIZE);
	if (v->t_last->nbyte == 0)
		v->eof = 1;
}

void	get_nlbyte(t_vars *v)
{
	size_t	indx;
	t_token	*tok;

	if (!v->t)
		read_next(v);
	if (v->t_last->nbyte == (size_t)-1)
		return ;
	tok = v->t;
	while (tok->nbyte)
	{
		indx = (v->nl_bytes + v->offset) % BUFFER_SIZE;
		if (indx > tok->nbyte - 1)
			return ;
		if (tok->buff[indx] == '\n')
		{
			v->nl_bytes++;
			return ;
		}
		v->nl_bytes++;
		if (indx == BUFFER_SIZE - 1)
		{
			read_next(v);
			tok = tok->next;
		}
	}
}

void	consume_token(t_vars *v, char *str)
{
	size_t	indx;
	t_token	*ptok;

	indx = 0;
	while (indx < v->nl_bytes)
	{
		str[indx] = v->t->buff[v->offset];
		v->offset++;
		indx++;
		if (v->offset == v->t->nbyte)
		{
			ptok = v->t;
			v->t = v->t->next;
			free(ptok);
			v->offset = 0;
			v->tok_len--;
		}
	}
}

char	*get_next_line(int fd)
{
	t_vars	*v;
	char	*str;

	v = files_fd(fd);
	if (!v)
		return (NULL);
	if (!v->t)
	{
		v->fd = fd;
		v->offset = 0;
		v->tok_len = 0;
	}
	v->nl_bytes = 0;
	get_nlbyte(v);
	if (v->nl_bytes == 0 || v->t->nbyte == (size_t)-1)
	{
		free(v->t);
		v->fin = 1;
		return (NULL);
	}
	str = malloc(v->nl_bytes + 1);
	consume_token(v, str);
	str[v->nl_bytes] = '\0';
	return (str);
}
