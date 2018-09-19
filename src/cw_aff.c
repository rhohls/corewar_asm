/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/18 10:47:45 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

// cw_aff:N
// 		R		3
// 	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},

int	cw_aff(char *str, int loc, t_asm_list *labels)
{
	int i;
	int ret;

	i = 3;
	ret = 2;
	(void)labels;
	if (check_register(str + i))
		return (ret + 1);
	error_(loc, "check the format on line : ");
	return (0);
}
