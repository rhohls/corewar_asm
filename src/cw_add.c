/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/20 10:22:29 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	cw_add(char *str, int loc, t_asm_list *labels)
{
	int i;
	int ret;
	int j;

	i = 4;
	ret = 2;
	(void)labels;
	if (check_register(str + i))
	{
		ret += 1;
		i = (str[6] == ',') ? 7 : 8;
		j = i;
		i = (str[j] == ' ') ? ++j : j;
		if (check_register(str + i))
		{
			ret += 1;
			i = (str[6] == ',') ? 7 : 8;
			j = i;
			i = (str[j] == ' ') ? ++j : j;
			if (check_register(str + i))
				return (ret + 1);
		}
	}
	error_(loc, "check the format on line : ");
	return (0);
}