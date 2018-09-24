/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:34:35 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/22 14:13:06 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char		*get_sti_opt_code(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (str[i] && str[i] != 'r' && str[i] != '%' && !ft_isdigit(str[i]))
		i++;
	i++;
	while (str[i] && str[i] != ',')
		i++;
	while (str[i] && str[i] != 'r' && str[i] != '%' && !ft_isdigit(str[i]))
		i++;
	j = i;
	while (str[j] != ',')
		j++;
	while (str[j] && str[j] != 'r' && str[j] != '%' && !ft_isdigit(str[j]))
		j++;
	s = check_sti(str, i, j);
	return (s);
}

char		*sti_arg1(char *str, char *s)
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
	t = hex(n, i_byte_no(str[i]));
	t1 = s;
	s = ft_strjoin(t1, t);
	free(t1);
	free(t);
	return (s);
}

char		*sti_arg2(char *str, char *s)
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
	free(t);
	if (!ft_isdigit(str[i]))
		n = long_atoi(&str[i + 1]);
	else
		n = long_atoi(&str[i]);
	n = clean_value(n);
	t = hex(n, i_byte_no(str[i]));
	t1 = s;
	s = ft_strjoin(t1, t);
	free(t1);
	free(t);
	return (s);
}

char		*sti_arg3(char *str, char *s)
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
	free(t1);
	t1 = s;
	s = ft_strjoin(t1, t);
	free(t);
	free(t1);
	return (s);
}

char		*sti(char *str)
{
	char		*s;

	s = get_sti_opt_code(str);
	s = sti_arg1(str, s);
	s = sti_arg2(str, s);
	s = sti_arg3(str, s);
	return (s);
}
