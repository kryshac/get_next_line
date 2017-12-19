/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:06:13 by ccristia          #+#    #+#             */
/*   Updated: 2017/12/19 20:57:02 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_add_stack(char **stack, char *buff)
{
	char	*stk;
	char	*tmp;
	int		i;
	int		j;
	int		ret;

	ret = 0;
	stk = *stack;
	i = 0;
	while (stk && stk[i])
		i++;
	j = 0;
	while (buff[j])
		j++;
	if ((tmp = (char *)malloc(sizeof(char) * (i + j + 1))) == NULL)
		return (0);
	i = i == 0 ? 0 : -1;
	while (stk && stk[++i])
		tmp[i] = stk[i];
	j = -1;
	while (buff[++j])
	{
		if (buff[j] == '\n' || buff[j] == EOF)
			ret = 1;
		tmp[i++] = buff[j];
	}
	tmp[i] = '\0';
	if (*stack)
		free(*stack);
	*stack = tmp;
	return (ret);
}

void	free_boff(char *buff, int size)
{
	while (size > 0)
		buff[--size] = '\0';
}

int	delete_first_line(char **stack)
{
	char *tmp;
	int	i;
	int	j;

	i = 0;
	while ((*stack)[i] != '\n' && (*stack)[i] != '\0')
		i++;
	i++;
	j = i;
	while ((*stack)[j] != '\0')
		j++;
	if ((tmp = (char *)malloc(sizeof(char) * (j - 1 + 1))) == NULL)
		return (0);
	j = 0;
	while ((*stack)[i])
		tmp[j++] = (*stack)[i++];
	tmp[j] = '\0';
	free(*stack);
	*stack = tmp;
	return (1);
}

char	*get_single_line(char *stack)
{
	char	*ret;
	int		i;

	i = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
		i++;
	if (stack[i] == '\n')
	{
		if ((ret = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
			return (NULL);
		ret[i--] = '\0';
		while (stack[i])
		{
			ret[i] = stack[i];
			i--;
		}
		return (ret);
	}
	else
		return (NULL);
}

int get_next_line(int const fd, char **line)
{
	static char	*stack;
	char		buff[BUFF_SIZE + 1];

	if (stack && (*line = get_single_line(stack)) != NULL)
	{
		delete_first_line(&stack);
		return (1);
	}
	while (read(fd, &buff, BUFF_SIZE))
	{
		buff[BUFF_SIZE] = '\0';
		if (ft_add_stack(&stack, buff))
		{
			*line = get_single_line(stack);
			delete_first_line(&stack);
			return (1);
		}
		free_boff(buff, BUFF_SIZE);
	}
	return (0);
}
