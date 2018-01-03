/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 21:54:28 by ccristia          #+#    #+#             */
/*   Updated: 2018/01/03 20:55:12 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_nod	*ft_checknod(t_nod **stack, int fd)
{
	t_nod	*tmp;

	tmp = *stack;
	if (!tmp->fd)
	{
		tmp->fd = fd;
		tmp->str = NULL;
		tmp->next = NULL;
		return (tmp);
	}
	else if (tmp->fd == fd)
		return (tmp);
	else if (tmp->next)
		return (ft_checknod(&(tmp->next), fd));
	else if ((tmp->next = (t_nod *)malloc(sizeof(t_nod))) == NULL)
	{
		//printf("return null\n");
		return (NULL);
	}
	tmp = tmp->next;
	tmp->fd = fd;
	tmp->str = NULL;
	tmp->next = NULL;
	return (tmp);
}

int		ft_addstack(t_nod *stack, char *buff)
{
	char	*tmp;
	int		i;
	int		j;
	int		ret;

	//printf("add stack - |%s|\n", stack->str);
	ret = 0;
	i = ft_strlen(buff);
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
	//printf("add stack (f) - |%s|\n", stack->str);
	return (ret);
}

int		ft_getline(t_nod *stack, char **line, int type)
{
	char	*tmp;
	int		size;
	int		i;

	size = 0;
	while (stack->str[size] && stack->str[size] != '\n')
		size++;
	//if (stack->str[size] != '\n' && size == 0)
	if ((size == 0 && type == 2) || (stack->str[size] != '\n' && type == 0))
		return (0);
	if ((tmp = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (-1);
	i = 0;
	while (i < size)
	{
		tmp[i] = stack->str[i];
		i++;
	}
	tmp[i] = '\0';
	*line = tmp;
	//printf("stack - |%s|\n", stack->str);
	if (!stack->str[i])
	{
		free(stack->str);
		stack->str = NULL;
	}
	else
		stack->str = ft_strcpy(stack->str, stack->str + size + 1);
	//printf("stack (f) - |%s|\n", stack->str);
	return (1);
}

void	ft_freenod(t_nod **stack, int fd)
{
	t_nod	*tmp;
	t_nod	*before;

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

int		get_next_line(int const fd, char **line)
{
	static t_nod	*stack;
	t_nod			*nod_curent;
	char			buff[BUFF_SIZE + 1];
	int				intret;

	if (fd < 0 || (!stack && (stack = (t_nod *)malloc(sizeof(t_nod))) == NULL))
		return (-1);
	if ((nod_curent = ft_checknod(&stack, fd + 1)) == NULL)
		return (-1);
	if (nod_curent->str && (intret = ft_getline(nod_curent, line, 0)) != 0)
	{
		//printf("return -> 0\n");
		return (intret);
	}
	while ((intret = (int)read(fd, &buff, BUFF_SIZE)) != 0)
	{
		if (intret == -1 || (buff[intret] = '\0') != '\0')
			return (-1);
		if ((intret = ft_addstack(nod_curent, buff)) == -1)
			return (-1);
		if (intret == 1)
		{
			//printf("return -> 1\n");
			return (ft_getline(nod_curent, line, 1));
		}
		ft_bzero(buff, sizeof(buff));
	}
	if (nod_curent->str && (intret = ft_getline(nod_curent, line, 2)) != 0)
	{
		//printf("return -> 3\n");
		return (intret);
	}
	ft_freenod(&stack, fd + 1);
	//printf("return -> 4\n");
	return (0);
}
