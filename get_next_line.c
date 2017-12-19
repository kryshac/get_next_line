/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:06:13 by ccristia          #+#    #+#             */
/*   Updated: 2017/12/19 19:26:16 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int add_char(char **buff, char **line)
// {
// 	int	i;
// 	int	j;
//
// 	i = 0;
// 	while ((*buff)[i] == '\n' || (*buff)[i] == '\0')
// 		i++;
// 	j = 0;
// 	while ((*buff)[j + i])
// 	{
// 		(*buff)[j] = (*buff)[j + i];
// 		j++
// 	}
// 	while ()
// 	// char *tmp;
// 	// int	i;
// 	// int j;
// 	//
// 	// //printf("buff - |%s|, line - |%s|\n", buff, *line);
// 	// i = 0;
// 	// while (buff[i] && buff[i] != '\n')
// 	// 	i++;
// 	// j = 0;
// 	// while (*line && (*line)[j])
// 	// 	j++;
// 	// printf("lungime - %d\n", j + i + 1);
// 	// tmp = (char *)malloc(sizeof(char) * (i + j + 1));
// 	// j = -1;
// 	// while (*line && (*line)[++j])
// 	// 	tmp[j] = (*line)[j];
// 	// i = 0;
// 	// while (buff[i] && buff[i] != '\n')
// 	// 	tmp[j++] = buff[i++];
// 	// tmp[j] = '\0';
// 	// // if (line)
// 	// // 	free(line);
// 	// *line = tmp;
// 	// //printf("finish - |%s|\n", *line);
// 	return (0);
// }

int	ft_add_stack(char **stack, char *buff)
{
	char	*stk;
	char	*tmp;
	int		i;
	int		j;

	stk = *stack;
	i = 0;
	while (stk && stk[i])
		i++;
	j = 0;
	while (buff[j])
		j++;
	tmp = (char *)malloc(sizeof(char) * (i + j + 1));
	if (tmp == NULL)
		return (0);
	i = i == 0 ? 0 : -1;
	while (stk && stk[++i])
		tmp[i] = stk[i];
	j = -1;
	while (buff[++j])
		tmp[i++] = buff[j];
	tmp[i] = '\0';
	if (*stack)
		free(*stack);
	*stack = tmp;
	return (1);
}

void	free_boff(char *buff, int size)
{
	while (size > 0)
		buff[--size] = '\0';
}

int get_next_line(int const fd, char **line)
{
	static char	*stack;
	char		buff[BUFF_SIZE + 1];
	//int		i;
	//*line = NULL;
	if (read(fd, &buff, BUFF_SIZE))
	{
		buff[BUFF_SIZE] = '\0';
		ft_add_stack(&stack, buff);
		free_boff(buff, BUFF_SIZE);
		printf("test return - <%s>\n", stack);
		return (1);
	}
	else
		return (0);
}
