/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:33:56 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/12 13:14:14 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char		*get_add_arg1_value(char *str)
{
	char		*s;
	char		*t;
	int			i;
	long long	n;

	i = 0;
	while (str[i] && !ft_isdigit(str[i]))
		i++;
	n = long_atoi(&str[i]);
	t = hex(n, 2);
	s = ft_strjoin("04 54 ", t);
	//free
	return (s);
}

char		*get_add_arg2_value(char *str, char *s)
{
	char		*ret;
	long long	n;
	char		*t;
	char		*t1;
	int			i;

	i = 0;
	while (str[i] && str[i] != 'r')
		i++;
	i++;
	n = long_atoi(&str[i]);
	t = hex(n, 2);
	ret = ft_strjoin(s, " ");
	t1 = ret;
	ret = ft_strjoin(t1, t);
	//free
	
	return (ret);
}

char		*get_add_arg3_value(char *str, char *s)
{
	char		*ret;
	long long	n;
	char		*t;
	char		*t1;
	int			i;

	i = 0;
	while (str[i] && str[i] != 'r')
		i++;
	i++;
	while (str[i] && str[i] != 'r')
		i++;
	i++;
	n = long_atoi(&str[i]);
	t = hex(n, 2);
	ret = ft_strjoin(s, " ");
	t1 = ret;
	ret = ft_strjoin(t1, t);
	//free(1);
	
	return (ret);
}

char		*add(char *str)
{
	char		*s;
	// char		*t;

	s = get_add_arg1_value(str);
	// t = s;
	s = get_add_arg2_value(str, s);
	//free
	// t = s;
	s = get_add_arg3_value(str, s);
	//free
	return (s);
}
