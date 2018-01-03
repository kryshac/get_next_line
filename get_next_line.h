/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 22:54:40 by ccristia          #+#    #+#             */
/*   Updated: 2018/01/03 19:35:36 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
// # include <unistd.h>
# include <fcntl.h>
// # include <stdlib.h>
// # include <string.h>
# include <stdio.h>
# include "libft/includes/libft.h"
# define BUFF_SIZE 5

typedef struct		s_nod
{
	int				fd;
	char			*str;
	struct s_nod	*next;
}					t_nod;
int					get_next_line(int const fd, char **line);
#endif
