/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 07:55:44 by fledwaba          #+#    #+#             */
/*   Updated: 2018/05/28 15:35:28 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*t;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	t = NULL;
	i = 0;
	while (s[i] != '\0')
		i++;
	j = i - start;
	if (j < (int)len)
		return (t);
	t = (char*)ft_memalloc((len + 1));
	if (!t)
		return (NULL);
	i = 0;
	j = start;
	while (len > 0)
	{
		t[i++] = s[j++];
		len--;
	}
	return (t);
}
