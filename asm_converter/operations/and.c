/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 14:03:10 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/21 15:23:12 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char		*get_and_opt_code(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (str[i] != ' ')
		i++;
	i++;
	j = i;
	while (str[j] != ',')
		j++;
	while (str[j] && str[j] != 'r' && str[j] != '%' && !ft_isdigit(str[j]))
		j++;
	s = check_and(str, i, j);
	return (s);
}

char		*and_arg1(char *str, char *s)
{
	int			i;
	long long	n;
	char		*t;
	char		*t1;

	i = 0;
	while (str[i] && str[i] != 'r' && str[i] != '%' && !ft_isdigit(str[i]))
		i++;
	if (!ft_isdigit(str[i]))
		n = long_atoi(&str[i + 1]);
	else
		n = long_atoi(&str[i]);
	n = clean_value(n);
	t = hex(n, get_byte_no(str[i]));
	t1 = s;
	s = ft_strjoin(t1, t);
	free(t1);
	free(t);
	return (s);
}

char		*and_arg2(char *str, char *s)
{
	int			i;
	long long	n;
	char		*t;
	char		*t1;

	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	while (str[i] && str[i] != 'r' && str[i] != '%' && !ft_isdigit(str[i]))
		i++;
	t = s;
	s = ft_strjoin(t, " ");
	free(t);
	if (!ft_isdigit(str[i]))
		n = long_atoi(&str[i + 1]);
	else
		n = long_atoi(&str[i]);
	n = clean_value(n);
	t = hex(n, get_byte_no(str[i]));
	t1 = s;
	s = ft_strjoin(t1, t);
	free(t1);
	free(t);
	return (s);
}

char		*and_arg3(char *str, char *s)
{
	int			i;
	long long	n;
	char		*t;
	char		*t1;

	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	i++;
	while (str[i] && str[i] != ',')
		i++;
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
	free(t);
	free(t1);
	return (s);
}

char		*and(char *str)
{
	char		*s;

	s = get_and_opt_code(str);
	s = and_arg1(str, s);
	s = and_arg2(str, s);
	s = and_arg3(str, s);
	return (s);
}
