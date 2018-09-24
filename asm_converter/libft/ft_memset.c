/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 07:40:51 by fledwaba          #+#    #+#             */
/*   Updated: 2018/05/25 16:01:50 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	int		i;
	char	*temp;

	i = 0;
	temp = str;
	while (i < (int)n)
	{
		temp[i] = c;
		i++;
	}
	return (temp);
}
