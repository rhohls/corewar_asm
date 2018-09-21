#include "../includes/asm.h"
#include <stdlib.h>

/*
** Removes whitespace and comments
** Then validates the commands 
** Then saves only commands(no labels) to a list
*/

int	is_white_space_rev(char *s, int start)
{
	int i;

	i = 0;
	// printf("end from s[%d] = %c\n", start, s[start]);
	while (((s[start - i] == ' ') || (s[start - i] == '\t')) && (s[start] != '\0'))
	{
	// printf("end from s[%d] = %c\n", start, s[start - i]);

			i++;
			if (start - i < 0)
				break ;
	}
	// i = (i > 0) ? i + 1 : i;
	return (i);
}

void	save_commands(char *str, t_asm **asm_main, int *valid, int loc)
{
	t_asm_list *temp;
	char *line;
	int i;
	int loc_hash;
	int	end;

	i = 0;
	loc_hash = len_to_char(str, '#');
	if (loc_hash == -1)
		loc_hash = len_to_char(str, ';');
	if (loc_hash == -1)
		loc_hash = len_to_char(str, '\0');
	end = is_white_space_rev(str, loc_hash - 1);
	(*valid)++;
	while (is_white_space(str[i]))
		i++;
	loc_hash -= i;
	// printf("loc_hash = %d, i = %d, str = |%s| end = %d\n", loc_hash,i, str, end);
	line = ft_strsub(str, i, loc_hash - end);
	// printf("loc_hash = %d, i = %d, line = |%s| end = %d\n", loc_hash,i, line, end);
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
	if (*valid < 0)
		save_commands(str + loc_colon, asm_main, valid, loc);
	temp = new_node(line, loc);
	add_node_front(&((*asm_main)->n_labels), temp);
}