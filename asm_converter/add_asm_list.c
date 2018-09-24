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

#include "header.h"

t_asm		*node(char *line)
{
	t_asm	*new;

	new = (t_asm*)malloc(sizeof(t_asm));
	new->next = NULL;
	if (!line)
		new->str = NULL;
	else
		new->str = ft_strdup(line);
	return (new);
}

void		add_asm_node(t_asm **h, char *line)
{
	t_asm		*t;
	t_asm		*new;

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
