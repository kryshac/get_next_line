/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:06:13 by ccristia          #+#    #+#             */
/*   Updated: 2017/12/21 19:53:32 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_sts(char *str1, char *str2)
{
	int		i;
	int		j;

	i = 0;
	while (str1 && str1[i])
		i++;
	j = 0;
	while (str2 && str2[j])
		j++;
	return (i + j);
}

int		ft_add_stack(char **stk, char *buff)
{
	char	*tmp;
	int		i;
	int		j;
	int		ret;

	if ((tmp = (char *)malloc(sizeof(char) * (ft_sts(*stk, buff) + 1))) == NULL)
		return (-1);
	i = -1;
	while (*stk && (*stk)[++i])
		tmp[i] = (*stk)[i];
	ret = 0;
	j = 0;
	i = i == -1 ? 0 : i;
	while (buff[j])
	{
		if (buff[j] == '\n')
			ret = 1;
		tmp[i++] = buff[j++];
	}
	tmp[i] = '\0';
	if (*stk)
		free(*stk);
	*stk = tmp;
	return (ret);
}

int		lenn_stack(char *stack)
{
	int	i;

	i = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
		i++;
	return (i + 1);
}

int		delete_first_line(char **stack)
{
	char	*tmp;
	int		i;
	int		j;

	i = lenn_stack(*stack);
	j = i;
	while ((*stack)[j] != '\0')
		j++;
	if (i == j)
	{
		if (*stack)
			free(*stack);
		*stack = NULL;
		return (1);
	}
	if ((tmp = (char *)malloc(sizeof(char) * (j - i + 1))) == NULL)
		return (-1);
	j = 0;
	while ((*stack)[i])
		tmp[j++] = (*stack)[i++];
	tmp[j] = '\0';
	free(*stack);
	*stack = tmp;
	return (1);
}

char	*get_single_line(char *stack, int type)
{
	char	*ret;
	int		i;

	i = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
		i++;
	if (stack[i] == '\n' || (type == 1 && stack[i] == '\0'))
	{
		if ((ret = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
			return (NULL);
		ret[i--] = '\0';
		while (i >= 0)
		{
			ret[i] = stack[i];
			i--;
		}
		return (ret);
	}
	else
		return (NULL);
}

int		while_boff(size_t buffsize, char *buff, char **stack, char **line)
{
	int	addstk;
	int	size;

	size = BUFF_SIZE;
	if (buffsize == (size_t)-1)
		return (-1);
	buff[buffsize] = '\0';
	if ((addstk = ft_add_stack(stack, buff)) == -1)
		return (-1);
	if (addstk == 1)
	{
		*line = get_single_line(*stack, 0);
		if (delete_first_line(stack) == -1)
			return (-1);
		while (size > 0)
			buff[--size] = '\0';
		return (1);
	}
	while (size > 0)
		buff[--size] = '\0';
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char	*stack[1024];
	char		buff[BUFF_SIZE + 1];
	size_t		buffsize;
	int			ret;

	if (fd < 0)
		return (-1);
	if (stack[fd] && (*line = get_single_line(stack[fd], 0)) != NULL)
	{
		if (delete_first_line(&stack[fd]) == -1)
			return (-1);
		return (1);
	}
	while ((buffsize = read(fd, &buff, BUFF_SIZE)) > 0)
	{
		if ((ret = while_boff(buffsize, buff, &stack[fd], line)) != 0)
			return (ret);
	}
	if (stack[fd])
	{
		*line = get_single_line(stack[fd], 1);
		delete_first_line(&stack[fd]);
		return (1);
	}
	return (0);
}
