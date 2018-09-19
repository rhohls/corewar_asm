/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/19 08:00:07 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/* 	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
cw_and:Y
		RRR		5
		IRR		6
		RIR		6
		IIR		7
		DRR		8
		RDR		8
		DDR		11
		DIR		9
		IDR		9 */

void adjust_ret(int *ret, int j, int *i, int hold, char *str)
{
    j = len_to_char(str + *i, ' ');
	(*i) += j;
	(*i)++;
	if (hold == 1)
		*ret += 1;
	else if ((hold == 2) || (hold == 3))
		*ret += 2;
}
int	cw_and(char *str, int loc, t_asm_list *labels)
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
        if ((hold = check_r_d_i(str + i, labels)) > 0)
	    {
    		adjust_ret(&ret, 0, &i, hold, str);
            if ((hold = check_r_d_i(str + i, labels)) > 0)
    	    {
                adjust_ret(&ret, 0, &i, hold, str);
			    return (ret);
            }
        }
    }
    error_(loc, "check the format on line : ");
	return (0);
}