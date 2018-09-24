/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 10:18:22 by fledwaba          #+#    #+#             */
/*   Updated: 2018/06/19 16:25:54 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				check_newline(char *s, int i)
{
	int x;

	if (s == NULL)
		return (-1);
	x = 0;
	while (s[x] || i == 0)
	{
		if (s[x] == '\n' || i == 0)
			return (1);
		x++;
	}
	return (-1);
}

static int				value(char **store, int i, int j)
{
	if ((i - j < 0 && i != -2) || ft_strlen(*store) > 0)
		return (1);
	else
		return (0);
}

static int				place(char **store, int fd, int j, int i)
{
	char	*temp;
	char	*buf;

	buf = (char*)ft_memalloc(BUFF_SIZE + 1);
	if (!buf)
		return (-1);
	while (check_newline(*store, i) != 1 && j <= i)
	{
		i = read(fd, buf, BUFF_SIZE);
		if (i == -1)
			return (-1);
		buf[i] = '\0';
		if (*store == NULL)
			*store = ft_strdup(buf);
		else
		{
			temp = *store;
			*store = ft_strjoin(temp, buf);
			free(temp);
		}
		j = i;
	}
	j = value(&(*store), i, j);
	free(buf);
	return (j);
}

int						get_next_line(int fd, char **line)
{
	static char		*store = NULL;
	char			*temp;
	int				i;
	int				j;

	if (!line || fd < 0 || BUFF_SIZE < 0)
		return (-1);
	j = place(&store, fd, -3, -2);
	if (j == -1)
		return (-1);
	i = 0;
	while (store[i] != '\n' && store[i] != '\0')
		i++;
	*line = ft_strsub(store, 0, i);
	if (store[i] != '\0')
		temp = ft_strsub(store, i + 1, ft_strlen(store) - i - 1);
	else
		temp = ft_strsub(store, 0, 0);
	free(store);
	store = ft_strdup(temp);
	free(temp);
	return (j);
}
