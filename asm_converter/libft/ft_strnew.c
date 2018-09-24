/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 08:52:50 by fledwaba          #+#    #+#             */
/*   Updated: 2018/05/26 16:23:11 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*t;
	size_t		i;

	t = NULL;
	t = (char*)malloc((size + 1));
	if (!t)
		return (NULL);
	i = 0;
	while (i < size)
	{
		t[i] = '\0';
		i++;
	}
	t[i] = '\0';
	return (t);
}
