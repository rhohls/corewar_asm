/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 08:36:01 by fledwaba          #+#    #+#             */
/*   Updated: 2018/07/29 14:06:23 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check(char const *s, int *j, int i)
{
	while (s[*j] != '\0')
		*j = *j + 1;
	*j = *j - 1;
	while (s[*j] == ' ' || s[*j] == '\n' || s[*j] == '\t')
		*j = *j - 1;
	return (*j - i);
}

static void		put(char *t, const char *s, int i, int j)
{
	int size;

	size = 0;
	while (i <= j)
	{
		t[size] = s[i];
		size++;
		i++;
	}
	t[size] = '\0';
}

char			*ft_strtrim(char const *s)
{
	char	*t;
	char	*empty;
	int		i;
	int		j;
	int		size;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
	{
		empty = (char*)malloc(1);
		empty[0] = '\0';
		return (empty);
	}
	j = 0;
	size = check(s, &j, i);
	t = NULL;
	t = (char*)malloc((size + 2));
	if (!t)
		return (NULL);
	put(t, s, i, j);
	return (t);
}
