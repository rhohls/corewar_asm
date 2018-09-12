/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/12 12:06:25 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	cw_sti(char *str)
{
	int reg;
	char *reg_bytes;
	int	dest;
	
	dest = 0;
	if ((BYTE(cursor->encoding) & R) != R)
		return ;
		
	reg = vm->mem_board[cursor->pc + 2];
	reg_bytes = cursor->reg[reg];
	if (BYTE(cursor->encoding) == RRR)
	{
		dest += get_reg(); //get info at reg
	}
	else if (BYTE(cursor->encoding) == RRD)
	{
		
	}
	else if (BYTE(cursor->encoding) == RIR || BYTE(cursor->encoding) == RDR)
	{
		
	}
	else if (BYTE(cursor->encoding) == RID || BYTE(cursor->encoding) == RDD)
	{
		
	}
	ft_memcpy();
}