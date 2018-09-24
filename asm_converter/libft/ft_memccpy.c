/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 14:02:09 by fledwaba          #+#    #+#             */
/*   Updated: 2018/05/29 11:47:00 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*temp;
	char		*temp2;
	size_t		i;

	i = 0;
	temp = (char*)src;
	temp2 = (char*)dest;
	while (i < n)
	{
		temp2[i] = temp[i];
		if ((unsigned char)temp2[i] == (unsigned char)c)
			return ((char*)&temp2[i + 1]);
		i++;
	}
	return (NULL);
}
