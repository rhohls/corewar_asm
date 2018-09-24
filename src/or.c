/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 09:27:35 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/23 11:09:06 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char		*get_or_opt_code(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (str[i] != ' ')
		i++;
	while (str[i] && str[i] != 'r' && str[i] != '%' && !ft_isdigit(str[i]))
		i++;
	j = i;
	while (str[j] != ',')
		j++;
	while (str[j] && str[j] != 'r' && str[j] != '%' && !ft_isdigit(str[j]))
		j++;
	s = check_or(str, i, j);
	return (s);
}

char		*or_arg1(char *str, char *s)
{
	long long	n;
	int			i;
	char		*t;
	char		*t1;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
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
	//free
	return (s);
}

char		*or_arg2(char *str, char *s)
{
	long long	n;
	int			i;
	char		*t;
	char		*t1;

	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	while (str[i] && str[i] != 'r' && str[i] != '%' && !ft_isdigit(str[i]))
		i++;
	t = s;
	s = ft_strjoin(t, " ");
	//free
	if (!ft_isdigit(str[i]))
		n = long_atoi(&str[i + 1]);
	else
		n = long_atoi(&str[i]);
	n = clean_value(n);
	t = hex(n, get_byte_no(str[i]));
	t1 = s;
	s = ft_strjoin(t1, t);
	
	//free
	return (s);
}

char		*or_arg3(char *str, char *s)
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

char		*or(char *str)
{
	char		*s;

	s = get_or_opt_code(str);
	s = or_arg1(str, s);
	s = or_arg2(str, s);
	s = or_arg3(str, s);
	return (s);
}
