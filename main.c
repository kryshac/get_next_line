/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:08:14 by ccristia          #+#    #+#             */
/*   Updated: 2017/12/21 20:55:04 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

int     main(void)
{
    //     char *line;
    // int             out;
    // int             p[2];
    // int             fd;
    // int             gnl_ret;
    //
    // fd = 1;
    // out = dup(fd);
    // pipe(p);
    // dup2(p[1], fd);
    // write(fd, "aaa", 3);
    // close(p[1]);
    // dup2(out, fd);
    // gnl_ret = get_next_line(p[0], &line);
    //     printf("line - |%s|\n", line);
    // if(strcmp(line, "aaa") == 0)
    // {
    //         printf("test 1\n");
    // }
    // if (gnl_ret == 0 || gnl_ret == 1)
    // {
    //         printf("test 2\n");
    // }
    // return (0);

	//
	//
	// char		*line;
	// int			fd;
	// int			ret;
	// char		*filename;
	//
	// filename = "../42FileChecker/srcs/gnl/gnl9_2.txt";
	// fd = open(filename, O_RDONLY);
	// if (fd > 2)
	// {
	// 	if (close(fd) == 0)
	// 	{
	// 		line = NULL;
	// 		ret = get_next_line(fd, &line);
	// 		if (ret != -1)
	// 			printf("-> must have returned '-1' when receiving a closed file descriptor\n");
	// 		else
	// 			printf("OK\n");
	// 	}
	// 	else
	// 	{
	// 		printf("An error occured while closing file descriptor associated with file %s\n", filename);
	// 		return (0);
	// 	}
	// }
	// else
	// 	printf("An error occured while opening file %s\n", filename);
	// return (0);

	// int 	file;
	// char	*str;
	//
	// file = open("test", O_RDONLY);
	// get_next_line(file, &str);
	// printf("<%s>\n", str);
	// get_next_line(file, &str);
	// printf("<%s>\n", str);
	// //free(str);
	// return (0);

	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;

	filename = "gnl5_2.txt";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf("line - %s\n", line);
			if (count_lines == 0 && strcmp(line, "123") != 0)
				errors++;
			if (count_lines == 1 && strcmp(line, "abc") != 0)
				errors++;
			count_lines++;
			if (count_lines > 50)
				break ;
		}
		close(fd);
		if (count_lines != 2)
			printf("-> must have returned '1' twice instead of %d time(s)\n", count_lines);
		if (errors > 0)
			printf("-> must have read \"123\" and \"abc\"\n");
		if (count_lines == 2 && errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
	return (0);



	// char    *line;
   // int             out;
   // int             p[2];
   // int             fd;
   //
   // fd = 1;
   // out = dup(fd);
   // pipe(p);
   //
   // dup2(p[1], fd);
   // write(fd, "aaa\nbbb\nccc\nddd\n", 16);
   // dup2(out, fd);
   // close(p[1]);
   // get_next_line(p[0], &line);
   // printf("test - |%s|\n", line);
   // if(strcmp(line, "aaa") == 0)
   // 	printf("nu merge1\n");
	// free(line);
   // get_next_line(p[0], &line);
   // if (strcmp(line, "bbb") == 0)
   // 		printf("nu merge\n");
	// free(line);
   // get_next_line(p[0], &line);
   // if (strcmp(line, "ccc") == 0)
   // 		printf("nu merge\n");
	// free(line);
   // get_next_line(p[0], &line);
   // if (strcmp(line, "ddd") == 0)
   // 		printf("nu merge\n");
	// free(line);
}
