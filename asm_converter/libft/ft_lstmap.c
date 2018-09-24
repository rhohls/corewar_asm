/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 08:24:15 by fledwaba          #+#    #+#             */
/*   Updated: 2018/05/30 10:02:20 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*temp;
	t_list	*temp1;
	t_list	*node;

	if (!lst)
		return (NULL);
	start = (t_list *)malloc(sizeof(t_list));
	if (!start)
		return (NULL);
	temp = lst;
	node = f(temp);
	temp = temp->next;
	start = node;
	temp1 = node;
	while (temp != NULL)
	{
		node = f(temp);
		temp1->next = node;
		temp = temp->next;
		temp1 = temp1->next;
	}
	temp1->next = NULL;
	return (start);
}
