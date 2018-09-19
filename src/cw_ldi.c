/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/19 09:26:38 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/* cw_ldi:Y	***ld D=2 (not 4)
		RRR		5
		IRR		6
		DRR		6
		RDR		6
		DDR		7
		IDR		7

		{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1} */

int	cw_ldi(char *str, int loc, t_asm_list *labels)
{
	int i;
	int ret;
	int hold;

	i = 3;
	ret = 2;
	(void)labels;
	if ((hold = check_r_d_i(str + i, labels)) > 0)
	{
		adjust_ret(&ret, 0, &i, hold, str);
		if ((hold = check_r_d(str + i, labels)) > 0)
		{
			ret += hold;
			i = len_to_char(str + i, ',');
			i = (str[i + 1] == ' ') ? i + 2 : i + 1;
			if (check_register(str + i))
				return (ret + 1);
		}
	}
	error_(loc, "check the format on line : ");
	return (0);
}
