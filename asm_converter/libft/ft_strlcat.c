/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 10:51:06 by fledwaba          #+#    #+#             */
/*   Updated: 2018/05/25 10:49:53 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int			i;
	int			max;
	int			j;

	i = 0;
	max = 0;
	while (dst[i] != '\0')
		i++;
	max = i;
	j = 0;
	while (src[j] != '\0')
		j++;
	if (i > (int)dstsize)
		max = (int)dstsize;
	max = max + j;
	j = 0;
	while (i < ((int)dstsize - 1) && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (max);
}
