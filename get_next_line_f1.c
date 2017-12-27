/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:10:17 by ccristia          #+#    #+#             */
/*   Updated: 2017/12/21 22:41:27 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	f_s(char *str, int type)
{
	int i;

	i = 0;
	while ((type == 0 && str && str[i]) || (type == 1 && str[i] != '\n'))
		i++;
	return (i);
}

int	ft_add_stack(char **stk, char *bf)
{
	char	*tp;
	char	*tmp;
	int		ret;
	int		i;

	tp = (char *)malloc(sizeof(char) * (f_s(*stk, 0) + f_s(bf, 0) + 1));
	if (tp == NULL)
		return (-1);
	tmp = tp;
	i = 0;
	while (*stk && (*stk)[i])
		*tp++ = (*stk)[i++];
	ret = 0;
	while (*bf)
	{
		if (*bf == '\n')
			ret = 1;
		*tp++ = *bf++;
	}
	*tp = '\0';
	if (*stk)
		free(*stk);
	*stk = tmp;
	return (ret);
}

int	get_line(char **line, char **stk, int type)
{
	char	*tmp;
	int		i;
	int		j;

	i = f_s(*stk, type);
	if ((tmp = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (-1);
	*line = tmp;
	j = 0;
	while ((type == 1 && (*stk)[j] != '\n') || (type == 0 && (*stk)[j]))
		*tmp++ = (*stk)[j++];
	*tmp = '\0';
	j = 0;
	while ((*stk)[j + i + 1])
	{
		(*stk)[j] = (*stk)[j + i + 1];
		j++;
	}
	(*stk)[j] = '\0';
	return (1);
}

int	check_stack(char **line, char **stk, int type)
{
	int	intret;
	int	i;

	intret = 0;
	if (type == 1)
	{
		i = 0;
		while ((*stk)[i] && (*stk)[i] != '\n')
			i++;
	}
	if (type == 1 && (*stk)[i] == '\n')
		intret = get_line(line, stk, type);
	else if (type == 0 && (*stk)[0])
	{
		intret = get_line(line, stk, type);
		free(*stk);
		*stk = NULL;
	}
	if (type == 0 && intret == 0 && *stk)
	{
		free(*stk);
		*stk = NULL;
	}
	return (intret);
}

int	get_next_line(int const fd, char **line)
{
	static char	*stk[1024];
	char		buff[BUFF_SIZE + 1];
	int			intret;
	int			i;

	if (fd < 0)
		return (-1);
	if (stk[fd] && (intret = check_stack(line, &stk[fd], 1)) != 0)
		return (intret);
	while ((intret = (int)read(fd, &buff, BUFF_SIZE)) != 0)
	{
		if (intret == -1)
			return (-1);
		buff[intret] = '\0';
		if ((intret = ft_add_stack(&stk[fd], buff)) == -1)
			return (-1);
		if (intret == 1)
			return (get_line(line, &stk[fd], 1));
		i = BUFF_SIZE;
		while (i >= 0)
			buff[i--] = '\0';
	}
	if (stk[fd] && (intret = check_stack(line, &stk[fd], 0)) != 0)
		return (intret);
	return (0);
}
