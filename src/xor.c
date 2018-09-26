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

void			get_xor_opt_code(char *str, int fd)
{
	int		i;
	int		j;
	int		n;

	n = 8;
	write(fd, &n, 1);
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
	n = check_encoding_byte(str, i, j);
	write(fd, &n, 1);
}

void			xor_arg1(char *str, int fd)
{
	int			i;
	long long	n;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i] && str[i] != 'r' && str[i] != '%' && !ft_isdigit(str[i]))
		i++;
	if (!ft_isdigit(str[i]))
		n = long_atoi(&str[i + 1]);
	else
		n = long_atoi(&str[i]);
	if (get_byte_no(str[i]) == 2)
		store_core_int_2(n, fd);
	else if (get_byte_no(str[i]) == 4)
		store_core_int_4(n, fd);
	else
		write(fd, &n, 1);
}

void			xor_arg2(char *str, int fd)
{
	int			i;
	long long	n;

	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	while (str[i] && str[i] != 'r' && str[i] != '%' && !ft_isdigit(str[i]))
		i++;
	if (!ft_isdigit(str[i]))
		n = long_atoi(&str[i + 1]);
	else
		n = long_atoi(&str[i]);
	n = clean_value(n);
	if (get_byte_no(str[i]) == 2)
		store_core_int_2(n, fd);
	else if (get_byte_no(str[i]) == 4)
		store_core_int_4(n, fd);
	else
		write(fd, &n, 1);
}

void			xor_arg3(char *str, int fd)
{
	int			i;
	long long	n;

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
	write(fd, &n, 1);
}

void			xor(char *str, int fd)
{
	get_xor_opt_code(str, fd);
	xor_arg1(str, fd);
	xor_arg2(str, fd);
	xor_arg3(str, fd);
}
