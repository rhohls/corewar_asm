/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/19 10:49:43 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/* cw_zjmp:N
		D		3
{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1} */

int	cw_zjmp(char *str, int loc, t_asm_list *labels)
{
	int ret;

	ret = 1;
	if (check_direct(str + 4, labels))
		return (ret + 2);
	error_(loc, "check the format on line : ");
	return (0);
}