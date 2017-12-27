/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_h.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 20:03:16 by ccristia          #+#    #+#             */
/*   Updated: 2017/12/26 21:54:18 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    set_nod(t_nod *stack, int fd)
{
    stack->fd = fd;
    stack->str = NULL;
    stack->next = NULL;
}

int     ft_check(char *buff)
{
    int i;

    i = 0;
    printf("string - |%s|\n", buff);
    while (buff[i])
    {
        if (buff[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

int     ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    ft_setNod(t_nod *stack, int fd, char *buff)
{
    if(!stack->fd)
    {
        stack->fd = fd;
        stack->str = (char *)malloc(sizeof(char) * (ft_strlen(buff) + 1));
        stack->next = NULL;
    }
    else if(stack->next && stack->fd != fd)
    {
        ft_setNod(stack->next, fd, buff);
    }
    else
    {
        stack->next = (t_nod *)malloc(sizeof(t_nod));
        ft_setNod(stack->next, fd, buff);
    }
}

int get_next_line(int const fd, char **line)
{
    static t_nod    *stack;
	char            buff[BUFF_SIZE + 1]https://github.com/kryshac/libftv1.git;
    int             intret;

    if (!stack && (stack = (t_nod *)malloc(sizeof(t_nod))) == NULL)
        return (-1);
	// while ((intret = (int)read(fd, &buff, BUFF_SIZE)) != 0)
	// {
	// 	if (intret == -1)
	// 		return (-1);
	// 	buff[intret] = '\0';
    //     ft_setNod(stack, fd, buff);
	// 	// if (ft_check(buff) == 1 && ft_setNod())
    //     //     return (1);
	// }
    return (0);
}