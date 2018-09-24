/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 09:40:28 by fledwaba          #+#    #+#             */
/*   Updated: 2018/05/25 16:11:30 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	const char	*t;
	int			i;
	int			j;

	t = src;
	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (t[j] != '\0')
	{
		dest[i] = t[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
