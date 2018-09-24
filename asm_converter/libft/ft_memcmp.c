/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 07:23:07 by fledwaba          #+#    #+#             */
/*   Updated: 2018/05/29 08:00:50 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char*)s1;
	t2 = (unsigned char*)s2;
	i = 0;
	while (i < (int)n)
	{
		if (t1[i] < t2[i])
			return (t1[i] - t2[i]);
		if (t1[i] > t2[i])
			return (t1[i] - t2[i]);
		i++;
	}
	return (0);
}
