/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:39:37 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/21 15:25:21 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char		*ld_n(char *str, int i)
{
	long long		n;
	char			*t;
	char			*t1;
	char			*s;

	i++;
	n = long_atoi(&str[i]);
	n = clean_value(n);
	t = hex(n, 8);
	s = ft_strjoin("02 90 ", t);
	free(t);
	while (str[i] && str[i] != 'r')
		i++;
	i++;
	n = long_atoi(&str[i]);
	t = hex(n, 2);
	t1 = s;
	s = ft_strjoin(t1, " ");
	free(t1);
	t1 = s;
	s = ft_strjoin(t1, t);
	free(t1);
	free(t);
	return (s);
}

char		*ld_no(char *str, int i)
{
	long long		n;
	char			*t;
	char			*t1;
	char			*s;

	n = long_atoi(&str[i]);
	n = clean_value(n);
	t = hex(n, 4);
	s = ft_strjoin("02 d0 ", t);
	free(t);
	while (str[i] && str[i] != 'r')
		i++;
	i++;
	n = long_atoi(&str[i]);
	t = hex(n, 2);
	t1 = s;
	s = ft_strjoin(t1, " ");
	free(t1);
	t1 = s;
	s = ft_strjoin(t1, t);
	free(t1);
	free(t);
	return (s);
}

char		*ld(char *str)
{
	int		i;
	char	*s;

	i = 0;
	while (str[i] && str[i] != '%' && !ft_isdigit(str[i]))
		i++;
	if (str[i] == '%')
		s = ld_n(str, i);
	else
		s = ld_no(str, i);
	return (s);
}
