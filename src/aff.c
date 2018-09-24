/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:27:30 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/12 13:15:36 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char		*aff(char *str)
{
	int				i;
	long long		n;
	char			*s;
	char			*t;

	i = 0;
	while (str[i] && str[i] != 'r')
		i++;
	if (str[i] == '\0')
		return (NULL);
	i++;
	n = long_atoi(&str[i]);
	n = clean_value(n);
	t = hex(n, 2);
	s = ft_strjoin("10 40 ", t);
	//free
	return (s);
}
