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

int check_float(char *line)
{
	int dot = 0;
	while ((*line >= '0' && *line <= '9') || *line == '.')
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
		printf("*line_incheck_float = %c\n", *line);
		line++;
	}
	if (*line == ' ' || *line == '\t' || *line == '\n' || *line  == '\0')
	{
		printf("****line_incheck_float = %c\n", *line);
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

int check_element_a(char *line, int num_a)
{

	while (*line == ' ' || *line == '\t')
		line++;
	if ((*line >= '0' || *line <= '9') && num_a <= 1)
	{
		if (check_float(line) == 0)
		{
			return (0);
		}
	}
	printf("*line = %c  ทำไมตรงนี้ไม่ขยับตาม line ใน check_float ที่โดน ++ ไป\n", *line);
	while (*line == ' ' || *line == '\t')
		line++;
	ft_split(line, ',');
	return 1;
}

int check_element(char *line, t_element *ele)
{

	while (*line != '\0' && *line != '\n')
	{
		printf("line === %s\n",line);
        if (*line == 'A' && ele->a == 0)
		{
			ele->a++;
			line++;
			if (check_element_a(line, ele->a) == 0)
			{
				return (0);
			}
		}
        // else if (*line == 'C')
        // {
		// 	ele.a++;
		// 	line++;
		// 	if (check_element_a(line, ele.a) == 0)
		// 		return (0);
		// }
        // else if (*line == 'p' && *(line + 1) == 'l')
        // {
		// 	ele.a++;
		// 	line++;
		// 	if (check_element_a(line, ele.a) == 0)
		// 		return (0);
		// }
        // else if (*line == 's' && *(line + 1) == 'p')
        // {
		// 	ele.a++;
		// 	line++;
		// 	if (check_element_a(line, ele.a) == 0)
		// 		return (0);
		// }
        // else if (*line == 'c' && *(line + 1) == 'y')
        // {
		// 	ele.a++;
		// 	line++;
		// 	if (check_element_a(line, ele.a) == 0)
		// 		return (0);
		// }

		else if (*line == '\t' || *line == ' ' || *line == '\n')
			line++;
		else{
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
	while (line)
	{
		if ((check_comment(line) == 1))//เป็นคอมเม้น ไปบรรทัดใหม่
		{
			free(line);
			line = get_next_line(fd);
		}
		if (check_element(line, &ele) == 0) //ถ้าไม่มีตัวไหนเลยหรือมีเกิน ให้จบโปรแกรมไปเลย
			return (0);
		free(line);
		line = get_next_line(fd);

	}
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
