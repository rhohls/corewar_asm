/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 09:00:09 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/25 10:34:03 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_byte		*convert_code(t_asm *list, int fd)
{
    t_byte   *h;
	t_asm_list *t;

	t = list->final_list;
	
	
	while (t)
	{
		if (ft_strstr(t->data, "live"))
			live(t->data, fd);
		else if (ft_strstr(t->data, "add"))
			add(t->data, fd);
//		else if (ft_strstr(t->data, "lldi"))
//			add_asm_node(&h, lldi(t->data));
//		/*else if (ft_strstr(t->data, "ldi"))
//			add_asm_node(&h, ldi(t->data));
//		else if (ft_strstr(t->data, "lld"))
//			add_asm_node(&h, lld(t->data));
//		else if (ft_strstr(t->data, "ld"))
///			add_asm_node(&h, ld(t->data));
//		else if (ft_strstr(t->data, "sti"))
//			add_asm_node(&h, sti(t->data));
//		else if (ft_strstr(t->data, "st"))
//			add_asm_node(&h, st(t->data));
		//..........add...........
//		else if (ft_strstr(t->data, "sub"))
//			add_asm_node(&h, sub(t->data));
//		else if (ft_strstr(t->data, "and"))
//			add_asm_node(&h, and(t->data));
//		else if (ft_strstr(t->data, "lfork"))
//			add_asm_node(&h, ft_lfork(t->data));
//		else if (ft_strstr(t->data, "fork"))
//			add_asm_node(&h, ft_fork(t->data));
//		else if (ft_strstr(t->data, "xor"))
//			add_asm_node(&h, xor(t->data));
//		else if (ft_strstr(t->data, "or"))
//			add_asm_node(&h, or(t->data));
//		else if (ft_strstr(t->data, "zjmp"))
//			add_asm_node(&h, zjmp(t->data));
//		else if (ft_strstr(t->data, "aff"))
//			add_asm_node(&h, aff(t->data));
		t = t->next;
	}
    return (h);
}
