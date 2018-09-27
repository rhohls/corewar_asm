/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/26 15:15:02 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	cw_live(char *str, int loc, t_asm_list *labels)
{
	int i;
	int ret;

	i = 5;
	ret = 1;
	if (check_direct(str + i, labels))
		return (ret + 4);
	error_(loc, "check the format on line : ");
	return (0);
}
