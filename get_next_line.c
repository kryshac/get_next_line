/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 21:54:28 by ccristia          #+#    #+#             */
/*   Updated: 2017/12/27 14:41:41 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

g_nod   *ft_checkNod(g_nod **stack, int fd)
{
    g_nod   *tmp;

    tmp = *stack;
    if (!tmp->fd)
    {
        tmp->fd = fd;
        tmp->str = NULL;
        tmp->next = NULL;
        return (tmp);
    }
    else if(tmp->fd == fd)
        return (tmp);
    else if (tmp->next)
        return (ft_checkNod(&(tmp->next), fd));
    else if ((tmp->next = (g_nod *)malloc(sizeof(g_nod))) == NULL)
        return (NULL);
    tmp = tmp->next;
    tmp->fd = fd;
    tmp->str = NULL;
    tmp->next = NULL;
    return (tmp);
}

int     ft_addStack(g_nod *stack, char *buff)
{
    char    *tmp;
    int     i;
    int     j;
    int     ret;

    ret = 0;
    i =  ft_strlen(buff);
    i += stack->str ? ft_strlen(stack->str) : 0;
    if ((tmp = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
        return (-1);
    i = 0;
    j = 0;
    while (stack->str && stack->str[i] &&
        (ret += stack->str[i] == '\n' ? 1 : 0) >= 0)
        tmp[j++] = stack->str[i++];
    i = 0;
    while (buff[i] && (ret += buff[i] == '\n' ? 1 : 0) >= 0)
        tmp[j++] = buff[i++];
    tmp[j] = '\0';
    if (stack->str)
        free(stack->str);
    stack->str = tmp;
    return (ret);
}

int     ft_getLine(g_nod *stack, char **line)
{
    char    *tmp;
    int     size;
    int     i;
    
    size = 0;
    while (stack->str[size] && stack->str[size] != '\n')
        size++;
    if (stack->str[size] != '\n' && size == 0)
        return (0);
    if ((tmp = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
        return (-1);
    i = -1;
    while (++i < size)
        tmp[i] = stack->str[i];
    tmp[i] = '\0';
    *line = tmp;
    if (!stack->str[i])
    {
        free(stack->str);
        stack->str = NULL;
    }
    else
        stack->str = ft_strcpy(stack->str, stack->str + size + 1);
    return (1);
}

void    ft_freeNod(g_nod **stack, int fd)
{
    g_nod   *tmp;
    g_nod   *before;

    tmp = *stack;
    before = NULL;
    while (tmp->fd != fd)
    {
        before = tmp;
        tmp = tmp->next;
    }
    if (!before)
        *stack = tmp->next ? tmp->next : NULL;
    else if (before)
        before->next = tmp->next ? tmp->next : NULL;
    free(tmp);
}

int     get_next_line(int const fd, char **line)
{
    static g_nod    *stack;
    g_nod           *nod_curent;
	char            buff[BUFF_SIZE + 1];
    int             intret;

    if (fd < 0 || (!stack && (stack = (g_nod *)malloc(sizeof(g_nod))) == NULL))
		return (-1);
    if ((nod_curent = ft_checkNod(&stack, fd)) == NULL)
        return (-1);
    if (nod_curent->str && (intret = ft_getLine(nod_curent, line)) != 0)
        return (intret);
	while ((intret = (int)read(fd, &buff, BUFF_SIZE)) != 0)
	{
		if (intret == -1 || (buff[intret] = '\0') != '\0')
			return (-1);
        if ((intret = ft_addStack(nod_curent, buff)) == -1)
            return (-1);
        if (intret == 1)
            return (ft_getLine(nod_curent, line));
        ft_bzero(buff, sizeof(buff));
	}
    if (nod_curent->str && (intret = ft_getLine(nod_curent, line)) != 0)
        return (intret);
    ft_freeNod(&stack, fd);
    return (0);
}