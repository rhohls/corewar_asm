/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:21:25 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/21 15:56:26 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char		*ft_lfork(char *str)
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
	t = hex(n, 4);
	s = ft_strjoin("0f ", t);
	free(t);
	return (s);
}
