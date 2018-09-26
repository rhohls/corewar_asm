/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/26 15:19:38 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	cw_xor(char *str, int loc, t_asm_list *labels)
{
	int i;
	int ret;
	int hold;

	i = 4;
	ret = 2;
	(void)labels;
	if ((hold = check_r_d_i(str + i, labels)) > 0)
	{
		adjust_ret(&ret, &i, hold, str);
		if (hold == 2)
			ret += 2;
		if ((hold = check_r_d_i(str + i, labels)) > 0)
		{
			adjust_ret(&ret, &i, hold, str);
			if (hold == 2)
				ret += 2;
			if (check_register(str + i))
				return (ret + 1);
		}
	}
	error_(loc, "check the format on line : ");
	return (0);
}
