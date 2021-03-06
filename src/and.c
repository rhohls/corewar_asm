/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 14:03:10 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/26 17:50:12 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		get_and_opt_code(char *str, int fd)
{
	int		i;
	int		j;
	int		n;

	n = 6;
	write(fd, &n, 1);
	i = 0;
	while (str[i] != ' ')
		i++;
	i++;
	j = i;
	while (str[j] != ',')
		j++;
	while (str[j] && str[j] != 'r' && str[j] != '%' && !ft_isdigit(str[j]))
		j++;
	n = check_encoding_byte(str, i, j);
	write(fd, &n, 1);
}

void		and_arg1(char *str, int fd)
{
	int			i;
	long long	n;

	i = 0;
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

void		and_arg2(char *str, int fd)
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

void		and_arg3(char *str, int fd)
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

void		and(char *str, int fd)
{
	get_and_opt_code(str, fd);
	and_arg1(str, fd);
	and_arg2(str, fd);
	and_arg3(str, fd);
}
