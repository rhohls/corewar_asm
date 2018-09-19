/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/19 10:34:47 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/* cw_st:Y
		RI		5
		RR		4
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0} */

int	cw_st(char *str, int loc, t_asm_list *labels)
{
	int i;
	int ret;
	int hold;

	i = 2;
	ret = 2;
	(void)labels;
	if (check_register(str + i))
	{
		ret += 1;
		i += len_to_char(str + i, ',');
		i = (str[i + 1] == ' ') ? i + 2 : i + 1;
		if ((hold = check_r_i(str + i)) > 0)
					return (ret + hold);
	}
	error_(loc, "check the format on line : ");
	return (0);
}