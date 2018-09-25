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

#include "../includes/asm.h"

int			i_byte_no(char c)
{
	if (c == '%')
		return (2);
	else if (ft_isdigit(c))
		return (2);
	else if (c == 'r')
		return (1);
	else
		return (-1);
}