/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:34:20 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/22 14:34:37 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char		*get_sub_op_code(void)
{
	char	*s;

	s = ft_strdup("05 54 ");
	return (s);
}

char		*sub_arg1(char *str, char *s)
{
	long long	n;
	int			i;
	char		*t;
	char		*t1;

	i = 0;
	while (str[i] && !ft_isdigit(str[i]))
		i++;
	n = long_atoi(&str[i]);
	t = hex(n, 2);
	t1 = s;
	s = ft_strjoin(t1, t);
	free(t);
	free(t1);
	return (s);
}

char		*sub_arg2(char *str, char *s)
{
	long long	n;
	int			i;
	char		*t;
	char		*t1;

	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	while (str[i] && !ft_isdigit(str[i]))
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

char		*sub_arg3(char *str, char *s)
{
	long long	n;
	int			i;
	char		*t;
	char		*t1;

	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	i++;
	while (str[i] && str[i] != ',')
		i++;
	while (str[i] && !ft_isdigit(str[i]))
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

char		*sub(char *str)
{
	char		*s;

	s = get_sub_op_code();
	s = sub_arg1(str, s);
	s = sub_arg2(str, s);
	s = sub_arg3(str, s);
	return (s);
}
