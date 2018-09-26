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

#include "../includes/asm.h"

int			check_sti(char *str, int i, int j)
{
	if (str[i] == '%' && str[j] == '%')
		return (104); //s = ft_strdup("0b 68 ");
	else if (str[i] == '%' && str[j] == 'r')
		return (100); //s = ft_strdup("0b 64 ");
	else if (ft_isdigit(str[i]) && str[j] == '%')
		return (120); //s = ft_strdup("0b 78 ");
	else if (ft_isdigit(str[i]) && str[j] == 'r')
		return (116); //s = ft_strdup("0b 74 ");
	else if (str[i] == 'r' && str[j] == '%')
		return (132); //s = ft_strdup("0b 84 ");
	else if (str[i] == 'r' && str[j] == 'r')
		return (84); //s = ft_strdup("0b 54 ");
	return (-1);
}
