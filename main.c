/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:08:14 by ccristia          #+#    #+#             */
/*   Updated: 2017/12/19 19:36:16 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int 	file;
	char	*str;

	file = open("test", O_RDONLY);
	printf("numar fisier - %d\n", file);
	file = open("test", O_RDONLY);
	printf("numar fisier - %d\n", file);
	while (get_next_line(file, &str))
		;
	printf("%s\n", str);
	return (0);
}
