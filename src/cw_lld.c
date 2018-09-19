/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/19 09:52:24 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
/* 
{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0}

cw_lld:Y
		DR		7
		IR		5  */

int	cw_lld(char *str, int loc, t_asm_list *labels)
{
	int i;
	int j;
	int ret;
	int hold;

	i = 3;
	ret = 2;
	if ((hold = check_d_i(str + i, labels)) > 0)
	{
		if (hold == 1)
			ret += 4;
		else
			ret += 2;
		j = len_to_char(str, ',');
		i = (str[j + 1] == ' ') ? j + 2 : j + 1;
		if (check_register(str + i))
			return (ret + 1);
	}
	error_(loc, "check the format on line : ");
	return (0);
}