/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:56:14 by fledwaba          #+#    #+#             */
/*   Updated: 2018/08/07 09:09:07 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		find_c(char const *s, char c, int size)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (i < size)
	{
		while (s[i] == c && i < size)
			i++;
		while (s[i] != c && i < size && s[i] != '\0')
			i++;
		k++;
	}
	if (s[i - 1] == c)
		k--;
	return (k);
}

static int		ft_space(char **p, char const *s, char c, int size)
{
	int i;
	int j;
	int x;

	i = 0;
	x = 0;
	while (i < size)
	{
		while (s[i] == c && i < size)
			i++;
		j = 0;
		while (s[i] != c && i < size)
		{
			i++;
			j++;
		}
		if (!(s[size - 1] == c && s[i] == '\0'))
			p[x] = (char*)malloc((j + 1));
		x++;
	}
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	int		size;
	char	**p;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	p = (char**)malloc(sizeof(char*) * (find_c(s, c, size) + 1));
	if (!p)
		return (NULL);
	i = ft_space(p, s, c, size);
	k = 0;
	while (i < size && k < find_c(s, c, size))
	{
		while (s[i] == c && i < size)
			i++;
		j = 0;
		while (s[i] != c && i < size)
			p[k][j++] = s[i++];
		p[k++][j] = '\0';
	}
	p[k] = NULL;
	return (p);
}
