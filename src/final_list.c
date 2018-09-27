/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:08:13 by swilson           #+#    #+#             */
/*   Updated: 2018/09/27 14:09:50 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		label_lenght(char *str)
{
	int i;

	i = 0;
	while (ft_strchr(LABEL_CHARS ,str[i]) && str[i])
		i++;
	return (i);
}

char	*set_final_line(t_asm_list *node, t_asm_list *labels)
{
	char *ret;
	int i;
	size_t len;
	char *loc;
	t_asm_list *label;

	i = 0;
	label = labels;
	i = len_to_char(node->data, LABEL_CHAR);
	while (label)
	{
		if ((label_lenght(node->data + i + 1)  == (int)ft_strlen(label->data)) &&
		ft_strnequ(node->data + i + 1, label->data, ft_strlen(label->data)))
		{
			loc = ft_itoa(label->location - node->location);
			len = ft_strlen(node->data) - ft_strlen(label->data) + ft_strlen(loc);
			ret = ft_memalloc(len);
			ft_strncat(ret, node->data, i);
			ft_strcat(ret, loc);
			ft_strcat(ret, node->data + i + ft_strlen(label->data) + 1);
			free(loc);
			return (ret);
		}
		label = label->next;
	}
	return (NULL);
}

void	save_final_list(t_asm **asm_main)
{
	char		*line;
	t_asm_list	*temp;
	t_asm_list	*node;


	line = NULL;
	temp = (*asm_main)->n_commands;
	while (temp)
	{
		if (ft_strchr(temp->data, LABEL_CHAR))
			line = set_final_line(temp, (*asm_main)->n_labels);
		else
			line = ft_strdup(temp->data);
		node = new_final_node(line, temp);
		free(line);
		add_node_front(&((*asm_main)->final_list), node);
		temp = temp->next;
	}
}
