/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 11:58:09 by fledwaba          #+#    #+#             */
/*   Updated: 2018/05/30 14:16:12 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		(*f)(&s[i]);
		i++;
	}
}
