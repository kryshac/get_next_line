/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:08:14 by ccristia          #+#    #+#             */
/*   Updated: 2017/12/19 20:27:08 by ccristia         ###   ########.fr       */
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



	char		*line;
	int			fd;
	int			ret;

	fd = -1;
	line = NULL;
	ret = get_next_line(fd, &line);
	if (ret != -1)
		printf("-> must have returned '-1' when receiving a negative file descriptor\n");
	else
		printf("OK\n");
	return (0);

	// int 	file;
	// char	*str;
	// int		i;
	//
	// i = 0;
	// file = open("test", O_RDONLY);
	// while (get_next_line(file, &str) == 1)
	// {
	// 	printf("<%s>\n", str);
	// 	free(str);
	// 	i++;
	// }
	// return (0);



	
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
