/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 08:43:10 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/18 08:50:10 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

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