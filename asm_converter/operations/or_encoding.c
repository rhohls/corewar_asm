/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or_encoding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:38:14 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/23 09:43:35 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char		*check_or(char *str, int i, int j)
{
	char		*s;

	s = NULL;
	if (str[i] == '%' && str[j] == '%')
		s = ft_strdup("07 a4 ");
	else if (str[i] == '%' && ft_isdigit(str[j]))
		s = ft_strdup("07 b4 ");
	else if (str[i] == '%' && str[j] == 'r')
		s = ft_strdup("07 94 ");
	else if (ft_isdigit(str[i]) && str[j] == '%')
		s = ft_strdup("07 e4 ");
	else if (ft_isdigit(str[i]) && ft_isdigit(str[j]))
		s = ft_strdup("07 f4 ");
	else if (ft_isdigit(str[i]) && str[j] == 'r')
		s = ft_strdup("07 d4 ");
	else if (str[i] == 'r' && str[j] == '%')
		s = ft_strdup("07 64 ");
	else if (str[i] == 'r' && ft_isdigit(str[j]))
		s = ft_strdup("07 74 ");
	else if (str[i] == 'r' && str[j] == 'r')
		s = ft_strdup("07 54 ");
	return (s);
}
