/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 08:43:10 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/11 19:04:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	exit_str(char *str)
{
	ft_putstr(str);
	exit (0);
}

int		error_(int line_no, char *output)
{
	ft_putstr(output);
	if (line_no)
		ft_putnbr(line_no);
	ft_putchar('\n');
	exit (0);
}