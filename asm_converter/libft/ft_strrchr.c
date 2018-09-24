/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:57:11 by fledwaba          #+#    #+#             */
/*   Updated: 2018/05/25 16:18:03 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*t;
	int			i;

	i = 0;
	t = s;
	while (t[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (t[i] == c)
			return ((char*)(t = &t[i]));
		i--;
	}
	return (NULL);
}
