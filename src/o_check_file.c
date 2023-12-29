/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_check_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:28:25 by tjukmong          #+#    #+#             */
/*   Updated: 2023/12/29 20:19:31 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_file(int argc, char **argv, t_element *ele)
{
	int	fd;

	if (argc != 2)
	{
		printf ("argc error\n");
		return (0);
	}
	if (checkdot_rt(argv[1]) != 0)
	{
		printf("File is not .rt\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("File error cannot open\n");
		return (0);
	}
	if (check_in_file(fd, ele) == 0)
	{
		printf("In file error\n");
		return (0);
	}
	printf("Happy Happy Happy\n");
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

int	check_in_file(int fd, t_element *ele)
{
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
	{
		printf("file empty\n");
		return (0);
	}
	while (line)
	{
		if (check_comment(line) != 1)
		{
			if (check_element(line, ele) == 0)
			{
				printf("error : check_element in check_in_file\n");
				return (0);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	if (count_element(ele) == 0)
		return (0);
	free(line);
	return (1);
}

int	check_element(char *line, t_element *ele) //เช็คบรรทัดz
{
	while ((*line >= 9 && *line <= 13) || *line == 32)
		line++;
	while (*line != '\0' && *line != '\n')
	{
		if (*line == 'A')
			return (check_element_a(line + 1, ele->a + 1));
		else if (*line == 'C')
		{
			ele->c++;
			line++;
			if (check_element_c(line, ele->c) == 1)
				return (1);
			printf("return (0) int check_element -> C\n");
			return (0);
		}
		else if (ft_strncmp(line, "pl", 2) == 0)
		{
			ele->pl++;
			line = line + 2;
			if (check_element_pl(line, ele->pl) == 1)
				return (1);
			printf("return (0) int check_element -> pl\n");
			return (0);
		}
		else if (ft_strncmp(line, "sp", 2) == 0)
		{
			ele->sp++;
			line = line + 2;
			if (check_element_sp(line, ele->sp) == 1)
				return (1);
			printf("return (0) int check_element -> sp\n");
			return (0);
		}
		else if (ft_strncmp(line, "cy", 2) == 0)
		{
			ele->cy++;
			line = line + 2;
			if (check_element_cy(line, ele->cy) == 1)
				return (1);
			printf("return (0) int check_element -> cy\n");
			return (0);
		}
		else if (*line == '\t' || *line == ' ' || *line == '\n')
			line++;
		else
			return (0);
	}
	return (1);
}

int	checkdot_rt(char *str)
{
	if (ft_strrchr(str, '.') == NULL)
	{
		printf("file error\n");
		exit(1);
	}
	if (ft_strncmp(ft_strrchr(str, '.'), ".rt", 10))
	{
		printf("file error\n");
		exit(1);
	}
	return (0);
}
