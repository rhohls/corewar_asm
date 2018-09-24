/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor_encoding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 09:34:38 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/23 09:39:08 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char		*check_xor(char *str, int i, int j)
{
	char		*s;

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
	return (s);
}
