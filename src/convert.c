/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 09:00:09 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/27 07:25:47 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_byte				*convert_code(t_asm *list, int fd)
{
	t_byte			*h;
	t_asm_list		*t;

	t = list->final_list;
	while (t)
	{
		if (ft_strstr(t->data, "live"))
			live(t->data, fd);
		else if (ft_strstr(t->data, "aff"))
			aff(t->data, fd);
		else if (ft_strstr(t->data, "lldi"))
			lldi(t->data, fd);
		else if (ft_strstr(t->data, "ldi"))
			ldi(t->data, fd);
		else if (ft_strstr(t->data, "lld"))
			lld(t->data, fd);
		else if (ft_strstr(t->data, "ld"))
			ld(t->data, fd);
		else if (ft_strstr(t->data, "sti"))
			sti(t->data, fd);
		else if (ft_strstr(t->data, "st"))
			st(t->data, fd);
		else if (ft_strstr(t->data, "add"))
			add(t->data, fd);
		else if (ft_strstr(t->data, "sub"))
			sub(t->data, fd);
		else if (ft_strstr(t->data, "and"))
			and(t->data, fd);
		else if (ft_strstr(t->data, "lfork"))
			ft_lfork(t->data, fd);
		else if (ft_strstr(t->data, "fork"))
			ft_fork(t->data, fd);
		else if (ft_strstr(t->data, "xor"))
			xor(t->data, fd);
		else if (ft_strstr(t->data, "or"))
			or(t->data, fd);
		else if (ft_strstr(t->data, "zjmp"))
			zjmp(t->data, fd);
		t = t->next;
	}
	return (h);
}
