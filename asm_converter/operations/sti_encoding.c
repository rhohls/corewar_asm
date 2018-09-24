/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti_encoding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:55:36 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/22 14:12:38 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char		*check_sti(char *str, int i, int j)
{
	char		*s;

	s = NULL;
	if (str[i] == '%' && str[j] == '%')
		s = ft_strdup("0b 68 ");
	else if (str[i] == '%' && str[j] == 'r')
		s = ft_strdup("0b 64 ");
	else if (ft_isdigit(str[i]) && str[j] == '%')
		s = ft_strdup("0b 78 ");
	else if (ft_isdigit(str[i]) && str[j] == 'r')
		s = ft_strdup("0b 74 ");
	else if (str[i] == 'r' && str[j] == '%')
		s = ft_strdup("0b 84 ");
	else if (str[i] == 'r' && str[j] == 'r')
		s = ft_strdup("0b 54 ");
	else
	{
		ft_putendl("Error");
		exit(0);
	}
	return (s);
}
