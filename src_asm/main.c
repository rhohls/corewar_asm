/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 07:11:41 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/06 07:24:22 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void init_asm(t_asm *asm_data)
{
	set_op_tab(asm_data);
	asm_data->file_lines = NULL;
}

void	init_header(t_header *header)
{
	 header->magic = (unsigned int)COREWAR_EXEC_MAGIC;
	 header->prog_size = 0;
	 ft_bzero(header->comment, COMMENT_LENGTH + 1);
	 ft_bzero(header->prog_name, PROG_NAME_LENGTH + 1);
}

int main(int argc, char **argv)
{
	t_asm	asm_data;
	t_header header;
	
	init_asm(&asm_data);
	
	if (argc < 2)
	{
		ft_putstr("usage!!, needs a file\n");
		exit(0);
	}
	else if (argc == 2)//for each file loop
	{
		//initialize header
		init_header(&header);
		//check if the file name is correct
		read_file(argv[1], &asm_data, &header);
		// strsplit on each line
		// if there is label remove it
		// (leave only instructions)
		// store current PC/adress and label in lnked list
		// verify each instruction (error check)
		// count bytes needed adjust PC/adress (important for label)
		// ?
		// either :
		// write instructions per line into file (leave empty space for label
		// come back write label later
		// or:
		// go through full file
		// error check and get all label adress
		// then write into file
		
		// also need header (which has file size)
		//
	}
	
	
	return (0);
}
