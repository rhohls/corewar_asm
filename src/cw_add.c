/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/18 10:44:22 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
// {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
			
// cw_add:Y
// 		RRR		5

int	cw_add(char *str, int loc, t_asm_list *labels)
{
	int i;
	int ret;

	i = 3;
	ret = 2;
	(void)labels;
	if (check_register(str + i))
	{
		ret += 1;
		i = (str[6] == ',') ? 7 : 8;
		i = (str[i] == ' ') ? ++i : i;
		if (check_register(str + i))
		{
			ret += 1;
			i = (str[6] == ',') ? 7 : 8;
			i = (str[i] == ' ') ? ++i : i;
			if (check_register(str + i))
				return (ret + 1);
		}
	}
	error_(loc, "check the format on line : ");
	return (0);
}