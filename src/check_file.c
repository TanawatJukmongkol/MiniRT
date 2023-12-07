#include "minirt.h"


int checkdot_rt(char *str)
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
	printf("file .rt is ok\n");
	return (0);
}

int check_comment(char *str)
{
	int i = 0;
	while (str[i])
	{
		i++;
		if (str[i] == '#')
			return (1);
	}
	return (0);
}

int count_split(char **str)
{
	int  i = 0;
	while (str[i])
	{
		i++;
	}
	printf("len_split = %d\n",i);
	return (i);
}

int check_float(char *line)
{
	int dot = 0;
	int i = 0;

	while ((*line >= '0' && *line <= '9') || *line == '.' || *line == '\0' || *line == ' ')
	{
		if (*line == '.')
		{
			dot++;
			if (dot >= 2)
			{
				printf("dot---- \n");
				return (0);
			}
		}
		else if (*line == '\0' || *line == ' ')
			return (i);
		line++;
		i++;
	}
	if (dot == 0)
		return (0);
	return (0);
}

double	ft_atof_dot(const char *nptr, double nbr)
{
	double	dot;

	dot = 0.1;
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		nbr = nbr + dot * (*nptr - '0');
		dot = dot/10;
		nptr++;
	}
	return (nbr);
}

double	ft_atof(const char *nptr)
{
	double	nbr;
	double	sign;

	nbr = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= '\a' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr)
	{
		if (*nptr >= '0' && *nptr <= '9')
			nbr = (nbr * 10) + (*nptr - '0');
		else
			break ;
		nptr++;
	}
	if (*nptr == '.')
	{
		nptr++;
		nbr = ft_atof_dot(nptr, nbr);
	}
	return (sign * nbr);
}

int check_int(char *str)
{
	int i = 0;
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		i++;
	}
	if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32 || str[i] == '\0')
	{
		return (1);
	printf("\n\nHello\n\n");
	}
	return (0);
}


// int check_int(char *str)
// {
// 	// int i = 0;
// 	printf("str = %s\n",str);
// 	printf("strlen = %zu\n", ft_strlen(str));
// 	// while (str[i] >= '0' && str[i] <= '9')
// 	return (1);
// }

int count_dot(char *str)
{
	int i = 0;
	int dot = 0;

	while (str[i])
	{
		if (str[i] == '.')
			dot++;
		i++;
	}
	return (dot);
}

int count_minus(char *str)
{
	int i = 0;
	int minus = 0;

	while (str[i])
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	return (minus);
}
int count_comma(char *str)
{
	int i = 0;
	int comma = 0;

	while (str[i])
	{
		if (str[i] == ',')
			comma++;
		i++;
	}
	return (comma);
}

int check_number(char *str)
{
	int i = 0;


	if (count_minus(str) >= 2 || count_dot(str) >= 2 || str[0] == '.' || str[ft_strlen(str) - 1] == '.')
			return (0);
	else if (str[0] == '-')
	{
		i = 1;
		while (str[i])
		{
			if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
				i++;
			else
				return (0);
		}
		if (i <= 1)
			return (0);
		return (1);
	}
	else if (check_int(str) == 1 || check_float(str) == 1)
	{
		printf("check int float = %d -> str = %s\n", check_float(str), str);
			// printf("str = %d\n", check_float(str));
		return (1);
	}

	return (0);

}

int	check_spiltxyz(char *line)
{
	char **xyz;
	int i = 0;

	xyz = ft_split(line, ',');
	if (count_comma(line) > 2)
		return (0);
	while (xyz[i])
	{
		if (check_number(xyz[i]) == 0)
		{
			return (0);
		}
		i++;
	}
	if (i == 3)
		return (1);
	return (0);
}


int check_spiltrgb(char *line)
{
	char **rgb;
	int i = 0;

	if (count_comma(line) >= 3)
		return (0);
	rgb = ft_split(line, ',');
	while (rgb[i])
	{
	printf("rgb[i] = %s\n",rgb[i]);
		if (check_int(rgb[i]) == 0) //221 ไม่ผ่านตรงนี้
		{
			printf("line = %s\n", line);
			printf("rgb = %s\n",rgb[i]);
			printf("return (0) check_splitrgb\n");
			return (0);
		}
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
		{
			printf("check_0-255\n");
			return (0);
		}
		i++;
	}
	if (i == 3)
	{
		return (1);
	}
	return (0);
}

int check_element_a(char *line, int num_a)
{
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32 || str[i] == '\0')
		return (0);
}

// int check_element_a(char *line, int num_a)
// {
// 	while (*line == ' ' || *line == '\t')
// 		line++;

// 	if ((*line >= '0' && *line <= '9') && num_a <= 1)
// 	{
// 		if (check_float(line) == 0)
// 		{
// 			printf("check_float in check_element_a\n");
// 			return (0);
// 		}
// 		line = line + check_float(line);
// 		while (*line == ' ' || *line == '\t')
// 		{
// 			line++;
// 		}
// 		if (check_spiltrgb(line) == 1) //ไม่ผ่านตรงนี้
// 		{
// 		// printf("line = %s\n", line);

// 		printf("return (1) in check_element_a \n");
// 			return (1);
// 		}
// 	}
// 	return (0);
// }

int check_element(char *line, t_element *ele) //เช็คบรรทัด
{

	while (*line != '\0' && *line != '\n')
	{
        if (*line == 'A')
		{
			ele->a++;
			line++;
			if (check_element_a(line, ele->a) == 1)
			{

				return (1);
			}
						printf("reutrn (0) in check_element \n");
			return (0);
		}
		else if (*line == '\t' || *line == ' ')
			line++;
		if (*line == '\0' || *line == '\n')
		{
			printf("\n\n\nmeow\n\n\n");
			return (0);//ตัวอื่นๆที่ไม่ใช่ element หรือ space ให้ออกหมด จบโปรแกรม
		}
	}
	return (1);
}

int check_in_file(int fd)
{
	char *line;
	t_element ele;
	ele.a = 0;
	ele.c = 0;
	ele.cy = 0;
	ele.pl = 0;
	ele.sp = 0;

	line = get_next_line(fd);
	if (line == NULL)
	{
		printf("file empty\n");
		return(0);
	}
	while (line) //วนเช็คในทุกบรรทัด
	{
		if ((check_comment(line) == 1))//เป็นคอมเม้น ไปบรรทัดใหม่
		{
			free(line);
			line = get_next_line(fd);
		}

		if (check_element(line, &ele) == 0)
		{ //ถ้าไม่มีตัวไหนเลยหรือมีเกิน ให้จบโปรแกรมไปเลย
			return (0);
		}
		free(line);
		line = get_next_line(fd);

	}
	free(line);
	return (1);
}

int check_file(int argc, char **argv)
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
	if (check_in_file(fd) == 0)//ใส่้ใน ข้อมูล
	{
		printf("In file error\n");
		return (0);
	}
	printf("Happy Happy Happy\n");
	close(fd);
	return 1;
}
