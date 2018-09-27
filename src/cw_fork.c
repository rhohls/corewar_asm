/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/27 07:58:19 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/asm.h"

int	cw_fork(char *str, int loc, t_asm_list *labels)
{
	printf("the string is |%s|\n", str);
	int i;
	int ret;

	i = go_to_param(str, 4);
	ret = 1;
	if (check_direct(str + i, labels))
		return (ret + 2);
	error_(loc, "check the format on line : ");
	return (0);
}
