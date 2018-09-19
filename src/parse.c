#include "../includes/asm.h"
#include <stdlib.h>

int	parse_list(t_asm **asm_main, int len)
{
	int			valid;
	t_asm_list	*temp;
	int			test;
	int			hold;

	valid = 0;
	temp = (*asm_main)->o_list;
	len = 0;
	while (temp)
	{
		if ((test = line_type(temp->data, &valid)) == 0)
			error_(temp->location, "invalid input on line : ");
		if (valid == 3)
			save_label(temp->data, asm_main, &valid, temp->location);
		else if (valid < 0)
		{
			hold = (*(g_func_ptr[(valid * -1)]))(temp->data);
			len += (hold > 0) ? hold : 0; // error_ if its zero
			save_commands(temp->data, asm_main, &valid, len);
		}
		temp = temp->next;
	}
	return (1);
}

int	line_type(char *line, int *valid)
{
	if (is_name(line, valid))
		return (1);
	else if (is_comment(line, valid))
		return (2);
	else if (is_label(line, valid))
		return (3);
	else if (is_blank(line, valid))
		return (4);
	else if (comments(line, valid))
		return (5);
	else if (is_command(line, valid))
		return (6);
	return (0);
}

int	balancing_quotations(char *line)
{
	int	i;

	i = 0;
	if (line[0] != '"')
		return (0);
	while (line[++i])
	{
		if (line[i] == '"')
		{
			if (line[i - 1] == '\\')
				continue ;
			else
				break;
		}
	}

	i++;
	while (line[i] && is_white_space(line[i]))
		i++;
	if (line[i] == '\0')
		return (1);
	return (0);
}
