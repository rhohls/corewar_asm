#include "../includes/asm.h"
#include <stdlib.h>


void	initialize(t_asm **asm_main)
{
	*asm_main = (t_asm*)malloc(sizeof(t_asm));
	(*asm_main)->header = (t_header*)malloc(sizeof(t_header));
	(*asm_main)->header->magic = (unsigned int)COREWAR_EXEC_MAGIC;
	(*asm_main)->header->prog_size = 0;
	ft_bzero((*asm_main)->header->comment, COMMENT_LENGTH + 1);
	ft_bzero((*asm_main)->header->prog_name, PROG_NAME_LENGTH + 1);
	(*asm_main)->o_list = NULL;
	(*asm_main)->n_commands = NULL;
	(*asm_main)->n_labels = NULL;
}

char	**init_commands(void)
{
	char	**ret;

	ret = (char **)malloc(sizeof(char*) *17);
	ret[0] = "live";
	ret[1] = "ld";
	ret[2] = "st";
	ret[3] = "add";
	ret[4] = "sub";
	ret[5] = "and";
	ret[6] = "or";
	ret[7] = "xor";
	ret[8] = "zjmp";
	ret[9] = "ldi";
	ret[10] = "sti";
	ret[11] = "folk";
	ret[12] = "lld";
	ret[13] = "lldi";
	ret[14] = "lfork";
	ret[15] = "aff";
	ret[16] = NULL;
	return (ret);
}


t_asm_list *new_node(char *line, int pos)
{
	t_asm_list *node;

	node = NULL;
	if (line)
	{	node = (t_asm_list*)malloc(sizeof(t_asm_list));
		node->data = ft_strdup(line);
		node->location = pos;
		node->next = NULL;
	}
	return (node);
}

void	add_node_front(t_asm_list **head, t_asm_list *node)
{
	t_asm_list *temp;

	temp = *head;
	if (!*head)
		*head = node;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = node;
	}
}
