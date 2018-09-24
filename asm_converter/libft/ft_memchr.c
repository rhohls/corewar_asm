/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 10:12:27 by fledwaba          #+#    #+#             */
/*   Updated: 2018/05/29 13:42:15 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char*)str;
	while (i < (int)n)
	{
		if ((unsigned char)temp[i] == (unsigned char)c)
		{
			temp = (char*)&str[i];
			return (temp);
		}
		i++;
	}
	return (NULL);
}
