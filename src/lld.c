/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:00:08 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/22 09:03:50 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char		*lld_n(char *str, int i)
{
	long long		n;
	char			*t;
	char			*t1;
	char			*s;

	i++;
	n = long_atoi(&str[i]);
	n = clean_value(n);
	t = hex(n, 8);
	s = ft_strjoin("0d 90 ", t);
	//free
	while (str[i] && str[i] != 'r')
		i++;
	i++;
	n = long_atoi(&str[i]);
	t = hex(n, 2);
	t1 = s;
	s = ft_strjoin(t1, " ");
	t1 = s;
	s = ft_strjoin(t1, t);
	
	//free(1);
	return (s);
}

char		*lld_no(char *str, int i)
{
	long long		n;
	char			*t;
	char			*t1;
	char			*s;

	n = long_atoi(&str[i]);
	n = clean_value(n);
	t = hex(n, 4);
	s = ft_strjoin("0d d0 ", t);
	//free
	while (str[i] && str[i] != 'r')
		i++;
	i++;
	n = long_atoi(&str[i]);
	t = hex(n, 2);
	t1 = s;
	s = ft_strjoin(t1, " ");
	t1 = s;
	s = ft_strjoin(t1, t);
	
	//free(1);
	return (s);
}

char		*lld(char *str)
{
	int		i;
	char	*s;

	i = 0;
	while (str[i] && str[i] != '%' && !ft_isdigit(str[i]))
		i++;
	if (str[i] == '%')
		s = lld_n(str, i);
	else
		s = lld_no(str, i);
	return (s);
}
