/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:34:58 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/22 10:47:43 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char		*st_op_code(char *str)
{
	int		i;
	char	*s;

	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	while (str[i] && str[i] != 'r' && !ft_isdigit(str[i]))
		i++;
	if (str[i] == 'r')
		s = ft_strdup("03 05 ");
	else
		s = ft_strdup("03 07 ");
	return (s);
}

char		*st_arg1(char *str, char *s)
{
	long long	n;
	int			i;
	char		*t;
	char		*t1;

	i = 0;
	while (str[i] && str[i] != 'r')
		i++;
	i++;
	n = long_atoi(&str[i]);
	t = hex(n, 2);
	t1 = s;
	s = ft_strjoin(t1, t);
	//free
	return (s);
}

char		*st_arg2(char *str, char *s)
{
	long long	n;
	int			i;
	char		*t;
	char		*t1;

	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	while (str[i] && !ft_isdigit(str[i]) && str[i] != 'r')
		i++;
	if (str[i] != 'r')
		n = long_atoi(&str[i]);
	else
		n = long_atoi(&str[i + 1]);
	t = hex(n, get_byte_no(str[i]));
	t1 = s;
	s = ft_strjoin(t1, " ");
	//free;
	t1 = s;
	s = ft_strjoin(t1, t);
	//free
	return (s);
}

char		*st(char *str)
{
	char		*s;

	s = st_op_code(str);
	s = st_arg1(str, s);
	s = st_arg2(str, s);
	return (s);
}
