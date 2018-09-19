/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/19 09:46:11 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/* {"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1}
cw_lfork:N ***sti D=2 (not 4)
		D		3 */

int	cw_lfork(char *str, int loc, t_asm_list *labels)
{
	int i;
	int ret;

	i = 4;
	ret = 1;
	if (check_direct(str + i, labels))
		return (ret + 2);
	error_(loc, "check the format on line : ");
	return (0);
}