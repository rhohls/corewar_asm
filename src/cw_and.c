/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/20 10:23:07 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

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

	i = 4;
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
			if (check_register(str + i))
				return (ret + 1);
		}
	}
	error_(loc, "check the format on line : ");
	return (0);
}