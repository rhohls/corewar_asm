/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 08:20:22 by fledwaba          #+#    #+#             */
/*   Updated: 2018/07/31 14:49:08 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*t;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	t = NULL;
	t = (char*)ft_memalloc(sizeof(t) * (i + j));
	if (t)
	{
		i = 0;
		j = 0;
		while (s1[i] != '\0')
		{
			t[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
			t[i++] = s2[j++];
		t[i] = '\0';
	}
	return (t);
}
