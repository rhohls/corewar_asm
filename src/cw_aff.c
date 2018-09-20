/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/20 10:22:37 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	cw_aff(char *str, int loc, t_asm_list *labels)
{
	int i;
	int ret;

	i = 4;
	ret = 2;
	(void)labels;
	if (check_register(str + i))
		return (ret + 1);
	error_(loc, "check the format on line : ");
	return (0);
}
