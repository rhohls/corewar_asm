/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:18:53 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/23 11:09:03 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*char        *check_xor(char *str, int i, int j)
{
    char       *s;

    s = NULL;
    if (str[i] == '%' && str[j] == '%')
        s = ft_strdup("08 a4 ");
    else if (str[i] == '%' && ft_isdigit(str[j]))
        s = ft_strdup("08 b4 ");
    else if (str[i] == '%' && str[j] == 'r')
        s = ft_strdup("08 94 ");
    else if (ft_isdigit(str[i]) && str[j] == '%')
        s = ft_strdup("08 e4 ");
    else if (ft_isdigit(str[i]) && ft_isdigit(str[j]))
        s = ft_strdup("08 f4 ");
    else if (ft_isdigit(str[i]) && str[j] == 'r')
        s = ft_strdup("08 d4 ");
    else if (str[i] == 'r' && str[j] == '%')
        s = ft_strdup("08 64 ");
    else if (str[i] == 'r' && ft_isdigit(str[j]))
        s = ft_strdup("08 74 ");
    else if (str[i] == 'r' && str[j] == 'r')
        s = ft_strdup("08 54 ");
    printf("s = %s\n", s);
    return (s);
}*/

char			*get_xor_opt_code(char *str)
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
	s = check_xor(str, i, j);
	return (s);
}

char			*xor(char *str)
{
	long long	n;
	int			i;
	char		*s;
	char		*t;
	char		*t1;

	s = get_xor_opt_code(str);
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
	i++;
	while (str[i] && ft_isdigit(str[i]))
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
	i++;
	while (str[i] && str[i] != 'r')
		i++;
	i++;
	n = long_atoi(&str[i]);
	t = hex(n, 2);
	t1 = s;
	s = ft_strjoin(t1, " ");
	//free
	t1 = s;
	s = ft_strjoin(t1, t);
	//free
	return (s);
}
