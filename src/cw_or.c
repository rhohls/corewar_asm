/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/19 10:09:21 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/* {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0}
cw_or:Y
		RRR		5
		IRR		6
		RIR		6
		IIR		7
		DRR		8
		RDR		8
		DDR		11
		DIR		9
		IDR		9 */

int	cw_or(char *str, int loc, t_asm_list *labels)
{
	int i;
	int ret;
	int hold;

	i = 2;
	ret = 2;
	(void)labels;
	if ((hold = check_r_d_i(str + i, labels)) > 0)
	{
		adjust_ret(&ret, 0, &i, hold, str);
		if (hold == 2)
			ret += 2;
		if ((hold = check_r_d_i(str + i, labels)) > 0)
		{
			adjust_ret(&ret, 0, &i, hold, str);
			if (hold == 2)
				ret += 2;
			if ((hold = check_r_d_i(str + i, labels)) > 0)
			{
				adjust_ret(&ret, 0, &i, hold, str);
				if (hold == 2)
					ret += 2;
				return (ret);
			}
		}
	}
	error_(loc, "check the format on line : ");
	return (0);
}