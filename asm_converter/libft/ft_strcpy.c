/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 09:18:43 by fledwaba          #+#    #+#             */
/*   Updated: 2018/06/02 14:19:42 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	const char	*t;
	int			i;

	i = 0;
	t = src;
	while (t[i] != '\0')
	{
		dest[i] = t[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
