/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:38:50 by fledwaba          #+#    #+#             */
/*   Updated: 2018/08/01 12:55:03 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *ne)
{
	char		*t;
	int			i;
	int			j;

	t = (char*)hay;
	i = 0;
	if (ne[i] == '\0')
		return (t);
	while (hay[i] != '\0')
	{
		j = 0;
		while (hay[i + j] == ne[j])
		{
			if (ne[j + 1] == '\0')
				return (t + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
