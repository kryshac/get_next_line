/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:08:14 by ccristia          #+#    #+#             */
/*   Updated: 2018/01/03 20:17:18 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void mt_assert(char test)
{
	if (test)
		printf(" \033[32mOK\033[0m");
	else
		printf(" \033[31mKO\033[0m");
}

// void	test01(void)
// {
// 	char 	*line;
// 	int		out;
// 	int		p[2];
// 	int		fd;
//
// 	printf("Test 01 ->");
// 	fd = 1;
// 	out = dup(fd);
// 	pipe(p);
// 	dup2(p[1], fd);
// 	write(fd, "aaa\nbbb\nccc\nddd\n", 16);
// 	dup2(out, fd);
// 	close(p[1]);
// 	get_next_line(p[0], &line);
// 	mt_assert(strcmp(line, "aaa") == 0);
// 	get_next_line(p[0], &line);
// 	mt_assert(strcmp(line, "bbb") == 0);
// 	get_next_line(p[0], &line);
// 	mt_assert(strcmp(line, "ccc") == 0);
// 	get_next_line(p[0], &line);
// 	mt_assert(strcmp(line, "ddd") == 0);
// 	printf("\n");
// }

// void	test02(void)
// {
// 	char		*line;
// 	int			fd;
// 	int			ret;
// 	int			count_lines;
// 	char		*filename;
// 	int			errors;
//
// 	printf("Test 02 ->");
// 	filename = "gnl1_1.txt";
// 	fd = open(filename, O_RDONLY);
// 	if (fd > 2)
// 	{
// 		count_lines = 0;
// 		errors = 0;
// 		line = NULL;
// 		while ((ret = get_next_line(fd, &line)) > 0)
// 		{
// 			if (count_lines == 0 && strcmp(line, "1234567") != 0)
// 				errors++;
// 			count_lines++;
// 			if (count_lines > 50)
// 				break;
// 		}
// 		close(fd);
// 		if (count_lines != 1)
// 		{
// 			printf("error 1");
// 			mt_assert(0); // printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
// 		}
// 		if (errors > 0)
// 		{
// 			printf("error 2");
// 			mt_assert(0); // printf("-> must have read \"1234567\" instead of \"%s\"\n", line);
// 		}
// 		if (count_lines == 1 && errors == 0)
// 		{
// 			printf("error 3");
// 			mt_assert(1); // printf("OK\n");
// 		}
// 	}
// 	else
// 	{
// 		printf("error 4");
// 		mt_assert(0); // printf("An error occured while opening file %s\n", filename);
// 	}
// 	printf("\n");
// }

void test03()
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;

	filename = "gnl1_2.txt";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			if (count_lines == 0 && strcmp(line, "1234567") != 0)
				errors++;
			printf("line - |%s|\n", line);
			if (count_lines == 1 && strcmp(line, "abcdefg") != 0)
				errors++;
			printf("line - |%s|\n", line);
			count_lines++;
			if (count_lines > 50)
				break ;
		}
		close(fd);
		if (count_lines != 2)
			printf("-> must have returned '1' twice instead of %d time(s)\n", count_lines);
		if (errors > 0)
			printf("-> must have read \"1234567\" and \"abcdefg\"\n");
		if (count_lines == 2 && errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
}
//
// void	test03(void)
// {
// 		char		*line1;
// 	char		*line2;
// 	char		*line3;
// 	int			fd1;
// 	int			fd2;
// 	int			fd3;
// 	int			ret1;
// 	int			ret2;
// 	int			ret3;
// 	char		*filename1;
// 	char		*filename2;
// 	int			errors;
//
// 	filename1 = "gnl11_1.txt";
// 	filename2 = "gnl11_2.txt";
// 	fd1 = open(filename1, O_RDONLY);
// 	fd2 = open(filename2, O_RDONLY);
// 	fd3 = -1;
// 	if (fd1 > 2 && fd2 > 2)
// 	{
// 		errors = 0;
// 		line1 = NULL;
// 		line2 = NULL;
// 		line3 = NULL;
//
// 		ret1 = get_next_line(fd1, &line1);
// 		if (ret1 != 1 || strcmp(line1, "The getdelim() function reads a line from stream, delimited by the character") != 0)
// 		{
// 			printf("-> must have returned '1' and read line #1 \"The getdelim() function reads a line from stream, delimited by the character\" from file %s\n", filename1);
// 			errors++;
// 		}
//
// 		ret1 = get_next_line(fd1, &line1);
// 		if (ret1 != 1 || strcmp(line1, "delimiter.  The getline() function is equivalent to getdelim() with the new-") != 0)
// 		{
// 			printf("-> must have returned '1' and read line #2 \"delimiter.  The getline() function is equivalent to getdelim() with the new-\" from file %s\n", filename1);
// 			errors++;
// 		}
//
// 		ret1 = get_next_line(fd1, &line1);
// 		if (ret1 != 1 || strcmp(line1, "line character as the delimiter.  The delimiter character is included as") != 0)
// 		{
// 			printf("-> must have returned '1' and read line #3 \"line character as the delimiter.  The delimiter character is included as\" from file %s\n", filename1);
// 			errors++;
// 		}
//
// 		ret1 = get_next_line(fd1, &line1);
// 		if (ret1 != 1 || strcmp(line1, "part of the line, unless the end of the file is reached.") != 0)
// 		{
// 			printf("-> must have returned '1' and read line #4 \"part of the line, unless the end of the file is reached.\" from file %s\n", filename1);
// 			errors++;
// 		}
//
// 		ret2 = get_next_line(fd2, &line2);
// 		if (ret2 != 1 || strcmp(line2, "The Festival de Radio France et Montpellier is a summer festival of opera and other music held in Montpellier.") != 0)
// 		{
// 			printf("-> must have returned '1' and read line #1 \"The Festival de Radio France et Montpellier is a summer festival of opera and other music held in Montpellier.\" from file %s\n", filename2);
// 			errors++;
// 		}
//
// 		ret2 = get_next_line(fd2, &line2);
// 		if (ret2 != 1 || strcmp(line2, "The festival concentrates on classical music and jazz with about 150 events, including opera, concerts, films, and talks. ") != 0)
// 		{
// 			printf("-> must have returned '1' and read line #2 \"The festival concentrates on classical music and jazz with about 150 events, including opera, concerts, films, and talks. \" from file %s\n", filename2);
// 			errors++;
// 		}
//
// 		ret2 = get_next_line(fd2, &line2);
// 		if (ret2 != 1 || strcmp(line2, "Most of these events are free and are held in the historic courtyards of the city or in the modern concert halls of Le Corum. ") != 0)
// 		{
// 			printf("-> must have returned '1' and read line #3 \"Most of these events are free and are held in the historic courtyards of the city or in the modern concert halls of Le Corum. \" from file %s\n", filename2);
// 			errors++;
// 		}
//
// 		ret2 = get_next_line(fd2, &line2);
// 		if (ret2 != 1 || strcmp(line2, "Le Corum cultural and conference centre contains 3 auditoriums. ") != 0)
// 		{
// 			printf("-> must have returned '1' and read line #4 \"Le Corum cultural and conference centre contains 3 auditoriums. \" from file %s\n", filename2);
// 			errors++;
// 		}
//
// 		ret3 = get_next_line(fd3, &line3);
// 		if (ret3 != -1)
// 		{
// 			printf("-> must have returned '-1' with invalid file descriptor\n");
// 			errors++;
// 		}
//
// 		ret1 = get_next_line(fd1, &line1);
// 		if (ret1 != 1 || strcmp(line1, "") != 0)
// 		{
// 			printf("-> must have returned '1' and read line #5 \"\" from file %s\n", filename1);
// 			errors++;
// 		}
//
// 		ret1 = get_next_line(fd1, &line1);
// 		if (ret1 != 1 || strcmp(line1, "The caller may provide a pointer to a malloced buffer for the line in") != 0)
// 		{
// 			printf("-> must have returned '1' and read line #6 \"The caller may provide a pointer to a malloced buffer for the line in\" from file %s\n", filename1);
// 			errors++;
// 		}
//
// 		ret1 = get_next_line(fd1, &line1);
// 		if (ret1 != 1 || strcmp(line1, "*linep, and the capacity of that buffer in *linecapp.  These functions") != 0)
// 		{
// 			printf("-> must have returned '1' and read line #7 \"*linep, and the capacity of that buffer in *linecapp.  These functions\" from file %s\n", filename1);
// 			errors++;
// 		}
//
// 		ret1 = get_next_line(fd1, &line1);
// 		if (ret1 != 1 || strcmp(line1, "expand the buffer as needed, as if via realloc().  If linep points to a NULL") != 0)
// 		{
// 			printf("-> must have returned '1' and read line #8 \"expand the buffer as needed, as if via realloc().  If linep points to a NULL\" from file %s\n", filename1);
// 			errors++;
// 		}
//
// 		ret1 = get_next_line(fd1, &line1);
// 		if (ret1 != 1 || strcmp(line1, "pointer, a new buffer will be allocated.  In either case, *linep and") != 0)
// 		{
// 			printf("-> must have returned '1' and read line #9 \"pointer, a new buffer will be allocated.  In either case, *linep and\" from file %s\n", filename1);
// 			errors++;
// 		}
//
// 		ret1 = get_next_line(fd1, &line1);
// 		if (ret1 != 1 || strcmp(line1, "*linecapp will be up-dated accordingly.") != 0)
// 		{
// 			printf("-> must have returned '1' and read line #10 \"*linecapp will be up-dated accordingly.\" from file %s\n", filename1);
// 			errors++;
// 		}
//
// 		ret2 = get_next_line(fd2, &line2);
// 		if (ret2 != 1 || strcmp(line2, "The city is a center for cultural events since there are many students. ") != 0)
// 		{
// 			printf("-> must have returned '1' and read line #5 \"The city is a center for cultural events since there are many students. \" from file %s\n", filename2);
// 			errors++;
// 		}
//
// 		ret2 = get_next_line(fd2, &line2);
// 		if (ret2 != 1 || strcmp(line2, "Montpellier has two large concerts venues: Le Zenith Sud (7.000 seats) and L'Arena (14.000 seats).") != 0)
// 		{
// 			printf("-> must have returned '1' and read line #6 \"Montpellier has two large concerts venues: Le Zenith Sud (7.000 seats) and L'Arena (14.000 seats).\" from file %s\n", filename1);
// 			errors++;
// 		}
//
// 		ret1 = get_next_line(fd1, &line1);
// 		if (ret1 != 0)
// 		{
// 			printf("-> must have returned '0' at the end of file %s\n", filename1);
// 			errors++;
// 		}
//
// 		ret2 = get_next_line(fd2, &line2);
// 		if (ret2 != 0)
// 		{
// 			printf("-> must have returned '0' at the end of file %s\n", filename2);
// 			errors++;
// 		}
//
// 		close(fd1);
// 		close(fd2);
// 		if (errors == 0)
// 			printf("OK\n");
// 	}
// 	else
// 		printf("An error occured while opening files %s and/or %s\n", filename1, filename2);
// }

int     main(void)
{
	//test01();
	//test03();
	//test03();
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	int			errors;

	fd = 0;
	count_lines = 0;
	errors = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("line -> |%s|\n", line);
		if (count_lines == 0 && strcmp(line, "1234567") != 0)
			errors++;
		if (count_lines == 1 && strcmp(line, "abcdefg") != 0)
			errors++;
		count_lines++;
		if (count_lines > 50)
			break ;
	}
	if (count_lines != 2)
		printf("-> must have returned '1' twice instead of %d time(s)\n", count_lines);
	if (errors > 0)
		printf("-> must have read \"1234567\" and \"abcdefg\"\n");
	if (count_lines == 2 && errors == 0)
		printf("OK\n");
	return (0);
}
