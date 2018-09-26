/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_encoding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 13:41:39 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/21 15:11:01 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			get_byte_no(char c)
{
	if (c == '%')
		return (4);
	else if (ft_isdigit(c))
		return (2);
	else if (c == 'r')
		return (1);
	else
		return (-1);
}

/*int			check_and(char *str, int i, int j)
{
	if (str[i] == '%' && str[j] == '%')
		return (164); //s = ft_strdup("06 a4 ");
	else if (str[i] == '%' && ft_isdigit(str[j]))
		return (180); //s = ft_strdup("06 b4 ");
	else if (str[i] == '%' && str[j] == 'r')
		return (); //s = ft_strdup("06 94 ");
	else if (ft_isdigit(str[i]) && str[j] == '%')
		s = ft_strdup("06 e4 ");
	else if (ft_isdigit(str[i]) && ft_isdigit(str[j]))
		s = ft_strdup("06 f4 ");
	else if (ft_isdigit(str[i]) && str[j] == 'r')
		s = ft_strdup("06 d4 ");
	else if (str[i] == 'r' && str[j] == '%')
		s = ft_strdup("06 64 ");
	else if (str[i] == 'r' && ft_isdigit(str[j]))
		s = ft_strdup("06 74 ");
	else if (str[i] == 'r' && str[j] == 'r')
		s = ft_strdup("06 54 ");
	return (s);
}*/
