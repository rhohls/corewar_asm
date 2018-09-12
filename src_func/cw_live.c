/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/12 12:06:25 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_player *get_player(t_vm *vm, int player_num)
{
	t_player	*player;
	t_list		*node;
	
	node = vm->player_list->start;
	while (node)
	{
		player = node->content;
		if (player->player_num == player_num)
			return (player);
		node = node->next;
	}
	return (NULL);
}


static void apply_life(t_vm *vm, int player_num)
{
	t_player	*player;
	player = get_player(vm, player_num);
	if (player)
		player->nbr_lives++;
}

void	cw_live(char *str)
{
	int player_num;
	
	player_num = get_int(&(vm->mem_board[cursor->pc + 2]));
	apply_life(vm, player_num);	
	cursor->pc += 5;
}