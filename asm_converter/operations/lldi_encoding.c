/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi_encoding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:10:39 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/22 09:31:19 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char		*check_lldi(char *str, int i, int j)
{
	char	*s;

	s = NULL;
	if (str[i] == '%' && str[j] == '%')
		s = ft_strdup("0e a4 ");
	else if (str[i] == '%' && ft_isdigit(str[j]))
		s = ft_strdup("0e b4 ");
	else if (str[i] == '%' && str[j] == 'r')
		s = ft_strdup("0e 94 ");
	else if (ft_isdigit(str[i]) && str[j] == '%')
		s = ft_strdup("0e e4 ");
	else if (ft_isdigit(str[i]) && ft_isdigit(str[j]))
		s = ft_strdup("0e f4 ");
	else if (ft_isdigit(str[i]) && str[j] == 'r')
		s = ft_strdup("0e d4 ");
	else if (str[i] == 'r' && str[j] == '%')
		s = ft_strdup("0e 64 ");
	else if (str[i] == 'r' && ft_isdigit(str[j]))
		s = ft_strdup("0e 74 ");
	else if (str[i] == 'r' && str[j] == 'r')
		s = ft_strdup("0e 54 ");
	return (s);
}
