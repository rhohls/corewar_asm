/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 08:40:44 by fledwaba          #+#    #+#             */
/*   Updated: 2018/06/04 07:55:43 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*temp1;
	const char	*temp2;
	int			i;

	i = 0;
	temp1 = s1;
	temp2 = s2;
	while (i < (int)n)
	{
		temp1[i] = temp2[i];
		i++;
	}
	return (temp1);
}
