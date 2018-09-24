/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:35:22 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/21 15:58:20 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char		*live(char *str)
{
	int				i;
	long long		n;
	char			*s;
	char			*t;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	if (str[i] == '\0')
		return (NULL);
	i++;
	n = long_atoi(&str[i]);
	n = clean_value(n);
	t = hex(n, 8);
	s = ft_strjoin("01 ", t);
	////free
	return (s);
}
