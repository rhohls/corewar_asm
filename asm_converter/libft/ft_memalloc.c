/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 08:44:42 by fledwaba          #+#    #+#             */
/*   Updated: 2018/06/04 16:28:18 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*t;
	char			*p;
	int				i;

	t = (char*)malloc(sizeof(void) * size);
	if (!t)
		return (NULL);
	i = 0;
	p = (char*)t;
	while (i < (int)size)
	{
		p[i] = 0;
		i++;
	}
	return (t);
}
