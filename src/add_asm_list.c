/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_asm_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:43:50 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/05 11:13:40 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_byte		*node(char *line)
{
	t_byte	*new;

	new = (t_byte*)malloc(sizeof(t_byte));
	new->next = NULL;
	if (!line)
		new->str = NULL;
	else
		new->str = ft_strdup(line);
	return (new);
}

void		add_asm_node(t_byte **h, char *line)
{
	t_byte		*t;
	t_byte		*new;

	new = node(line);
	t = *h;
	if (t == NULL)
	{
		*h = new;
		return ;
	}
	while (t->next)
		t = t->next;
	t->next = new;
}
