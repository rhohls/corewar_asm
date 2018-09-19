/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/19 09:48:27 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/* cw_live:N
		D		5

{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0} */

int	cw_live(char *str, int loc, t_asm_list *labels)
{
	int i;
	int ret;

	i = 4;
	ret = 1;
	if (check_direct(str + i, labels))
		return (ret + 4);
	error_(loc, "check the format on line : ");
	return (0);
}