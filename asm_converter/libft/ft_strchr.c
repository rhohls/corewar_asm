/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:36:38 by fledwaba          #+#    #+#             */
/*   Updated: 2018/05/23 07:37:52 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;
	const char	*t;

	t = s;
	i = 0;
	while (t[i] != '\0')
	{
		if (t[i] == c)
			return ((char*)(t = &t[i]));
		i++;
	}
	if (t[i] == c)
		return ((char*)(t = &t[i]));
	return (NULL);
}
