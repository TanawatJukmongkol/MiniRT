/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_check_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:28:25 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/12 12:50:05 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_file(int argc, char **argv, t_element *ele)
{
	int	fd;

	if (argc == 1)
		return (\
		printf("Error\nNo argument passed.\nusage: ./miniRT <asset.rt>\n"), 0);
	if (argc != 2)
		return (printf("Error\nInvalid number of arguments passed.\n"), 0);
	if (checkdot_rt(argv[1]) == 0)
		return (\
		printf("Error\nInvalid file extension. (expected .rt)\n"), 0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (printf("Error\nCannot open file.\n"), 0);
	}
	if (check_in_file(fd, ele) == 0)
	{
		close(fd);
		return (0);
	}
	return (1);
}

void	set_ele(t_element *ele)
{
	ele->a = 0;
	ele->c = 0;
	ele->l = 0;
	ele->cy = 0;
	ele->pl = 0;
	ele->sp = 0;
}

int	check_in_file_util(char *line, t_element *ele, size_t line_nbr, int fd)
{
	if (check_comment(line) != 1)
	{
		if (check_element(line, ele) == 0)
		{
			printf("Error\nInvalid element at line number %ld:\n", line_nbr);
			printf("> %s\n", line);
			free_gnl(fd, line);
			return (0);
		}
	}
	return (1);
}

int	check_in_file(int fd, t_element *ele)
{
	char	*line;
	size_t	line_nbr;

	line = get_next_line(fd);
	line_nbr = 1;
	if (line == NULL)
	{
		printf("file empty\n");
		free_gnl(fd, line);
		return (0);
	}
	while (line)
	{
		if (check_in_file_util(line, ele, line_nbr, fd) == 0)
			return (0);
		free(line);
		line = get_next_line(fd);
		line_nbr++;
	}
	free_gnl(fd, line);
	if (count_element(ele) == 0)
		return (0);
	return (1);
}

int	check_element(char *line, t_element *ele)
{
	while ((*line >= 9 && *line <= 13) || *line == 32)
		line++;
	while (*line != '\0' && *line != '\n')
	{
		if (*line == 'A')
			return (check_element_a(++line, ++ele->a));
		else if (*line == 'C')
			return (check_element_c(++line, ++ele->c));
		else if (*line == 'L')
			return (check_element_l(++line, ++ele->l));
		else if (ft_strncmp(line, "pl", 2) == 0)
			return (check_element_pl(line + 2, ++ele->pl));
		else if (ft_strncmp(line, "sp", 2) == 0)
			return (check_element_sp(line + 2, ++ele->sp));
		else if (ft_strncmp(line, "cy", 2) == 0)
			return (check_element_cy(line + 2, ++ele->cy));
		else if (*line == '\t' || *line == ' ' || *line == '\n')
			line++;
		else
			return (0);
	}
	return (1);
}
