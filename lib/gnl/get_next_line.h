/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:42:31 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/03 13:10:43 by Tanawat J.       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

# define FD_MAX	1000
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_token
{
	char			buff[BUFFER_SIZE];
	struct s_token	*next;
	size_t			nbyte;
}				t_token;

typedef struct s_vars
{
	int		fd;
	int		eof;
	int		fin;
	t_token	*t;
	t_token	*t_last;
	size_t	offset;
	size_t	nl_bytes;
	size_t	tok_len;
}				t_vars;

char	*get_next_line(int fd);
t_vars	*files_fd(int fd);
void	free_gnl(int fd, char *str);

#endif
