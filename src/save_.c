#include "../includes/asm.h"
#include <stdlib.h>

/*
** Removes whitespace and comments
** Then validates the commands 
** Then saves only commands(no labels) to a list
*/

void	save_commands(char *str, t_asm **asm_main, int *valid, int loc)
{
	// t_asm_list *new;
	t_asm_list *temp;
	char *line;
	int i;
	int loc_hash;

	i = 0;
	loc_hash = len_to_char(str, '#');
	if (loc_hash == -1)
		loc_hash = len_to_char(str, '\0'); // till # or '\0'
	(*valid)++;

	while (is_white_space(str[i]))
		i++;
	line = ft_strsub(str, i, loc_hash);

	temp = new_node(line, loc);

	add_node_front(&((*asm_main)->n_commands), temp);
}

void	save_label(char *str, t_asm **asm_main, int *valid, int loc)
{
	t_asm_list *temp;
	char *line;
	int loc_colon;
	int j;
	int len;
	//double check what you are returning

	loc_colon = len_to_char(str, LABEL_CHAR);
	j = 0;
	len = 0;
	while (is_white_space(str[j]))
		j++;
	line = ft_strsub(str, j, loc_colon);
	loc_colon++;
	while (is_white_space(str[loc_colon]))
		loc_colon++;
	line_type(str + loc_colon, valid);
	printf("valid =  %d\n", *valid);
	printf("valid in save label = %d loc = %d\n", *valid, loc_colon);
	if (*valid < 0)
		save_commands(str + loc_colon, asm_main, valid, loc);
	temp = new_node(line, loc);
	add_node_front(&((*asm_main)->n_labels), temp);
}