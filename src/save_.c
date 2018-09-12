#include "../include/asm.h"
#include <stdlib.h>

void	save_commands(char *str, t_asm **asm_main, int *valid)
{
	t_asm_list *new;
	t_asm_list *temp;
	char *line;
	int i;
	int j;

	i = 0;
	j = len_to_char(str, '#');
	if (j == -1)
		j = len_to_char(str, '\0'); // till # or '\0'
	new = (*asm_main)->n_commands;
	(*valid)++;
	while (is_white_space(str[i]))
		i++;
	line = ft_strsub(str, i, j);
	temp = new_node(line, 000);
	add_node_front(&new, temp);
}

void	save_label(char *str, t_asm **asm_main, int *valid)
{
	t_asm_list *new;
	t_asm_list *temp;
	char *line;
	int i;
	int j;
	//double check what you are returning

	new = (*asm_main)->n_labels;
	i = len_to_char(str, LABEL_CHAR);
	j = 0;
	while (is_white_space(str[j]))
		j++;
	line = ft_strsub(str, j, i);
	while (is_white_space(str[i]))
		i++;
	*valid = what_is_it(str + i, valid);
	temp = new_node(line, 000);
	add_node_front(&new, temp);
}