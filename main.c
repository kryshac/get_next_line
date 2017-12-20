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

int	main(void)
{
	int 	file;
	int 	file1;
	char	*str;
	int		i;

	i = 0;
	file = open("test", O_RDONLY);
	file1 = open("abc", O_RDONLY);
	while (i < 3)
	{
		get_next_line(file, &str);
		printf("<%s>\n", str);
		free(str);
		get_next_line(file1, &str);
		printf("<%s>\n", str);
		free(str);
		i++;
	}
	return (0);
}
