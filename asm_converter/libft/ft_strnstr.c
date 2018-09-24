/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 08:09:43 by fledwaba          #+#    #+#             */
/*   Updated: 2018/05/30 12:39:31 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *ne, size_t len)
{
	char	*t;
	int		i;
	int		j;

	t = (char*)hay;
	i = 0;
	while (i < (int)len && hay[i] != '\0')
	{
		j = 0;
		while (hay[i + j] == ne[j] && ne[j] != '\0' && (i + j) < (int)len)
			j++;
		if (ne[j] == '\0')
			return (t + i);
		i++;
	}
	return (NULL);
}
