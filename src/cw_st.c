/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/20 10:24:24 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	cw_st(char *str, int loc, t_asm_list *labels)
{
	int i;
	int ret;
	int hold;

	i = 3;
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