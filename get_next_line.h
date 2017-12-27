/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 22:54:40 by ccristia          #+#    #+#             */
/*   Updated: 2017/12/27 04:34:50 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libft/includes/libft.h"
# define BUFF_SIZE 1

typedef struct g_list {
    int             fd;
    char            *str;
    struct g_list   *next;
}                   g_nod;
int                 get_next_line(int const fd, char **line);
#endif
