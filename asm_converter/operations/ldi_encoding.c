/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi_encoding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:25:39 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/21 15:34:31 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int			i_byte_no(char c)
{
	if (c == '%')
		return (4);
	else if (ft_isdigit(c))
		return (4);
	else if (c == 'r')
		return (2);
	else
		return (-1);
}

char		*check_ldi(char *str, int i, int j)
{
	char		*s;

	s = NULL;
	if (str[i] == '%' && str[j] == '%')
		s = ft_strdup("0a a4 ");
	else if (str[i] == '%' && ft_isdigit(str[j]))
		s = ft_strdup("0a b4 ");
	else if (str[i] == '%' && str[j] == 'r')
		s = ft_strdup("0a 94 ");
	else if (ft_isdigit(str[i]) && str[j] == '%')
		s = ft_strdup("0a e4 ");
	else if (ft_isdigit(str[i]) && ft_isdigit(str[j]))
		s = ft_strdup("0a f4 ");
	else if (ft_isdigit(str[i]) && str[j] == 'r')
		s = ft_strdup("0a d4 ");
	else if (str[i] == 'r' && str[j] == '%')
		s = ft_strdup("0a 64 ");
	else if (str[i] == 'r' && ft_isdigit(str[j]))
		s = ft_strdup("0a 74 ");
	else if (str[i] == 'r' && str[j] == 'r')
		s = ft_strdup("0a 54 ");
	return (s);
}
