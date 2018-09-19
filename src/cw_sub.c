/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/19 10:40:39 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/* {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0}
cw_sub:Y
		RRR		5 */

int	cw_sub(char *str, int loc, t_asm_list *labels)
{
	int i;
	int ret;

	i = 2;
	ret = 2;
	(void)labels;
	if (check_register(str + i))
	{
		ret += 1;
		i += len_to_char(str + i, ',');
		i = (str[i + 1] == ' ') ? i + 2 : i + 1;
		if (check_register(str + i))
		{
			ret += 1;
			i += len_to_char(str + i, ',');
			i = (str[i + 1] == ' ') ? i + 2 : i + 1;
			if (check_register(str + i))
				return (ret + 1);
		}
	}
	error_(loc, "check the format on line : ");
	return (0);
}