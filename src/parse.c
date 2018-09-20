#include "../includes/asm.h"
#include <stdlib.h>

t_asm_list	*sanitised_command(int loc, t_asm_list *list)
{
	t_asm_list *commands;

	commands = list;
	while (commands)
	{
		if (commands->location == loc)
			return (commands);
		commands = commands->next;
	}
	return (NULL);
}

void	save_locations(t_asm **asm_main)
{
	t_asm_list	*temp;
	t_asm_list	*command;
	t_asm_list	*labels;
	int			size;
	int			valid;

	temp = (*asm_main)->o_list;
	labels = (*asm_main)->n_labels;
	while (temp)
	{

		line_type(temp->data, &valid);
		if (valid < 0)
		{
			command = sanitised_command(temp->location, (*asm_main)->n_commands);
			if (command != NULL)
			{
				printf("~~input string |%s| \n",command->data );
				printf("calling function number: %d~~\n", valid * -1);
				size = (*(g_func_ptr[(valid * -1)]))(command->data, command->location, (*asm_main)->n_labels);
				if (size)
					command->location = size;
			}
		}
		temp = temp->next;
	}
}

int	parse_list(t_asm **asm_main, int len)
{
	int			valid;
	t_asm_list	*temp;
	int			test;

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
			save_commands(temp->data, asm_main, &valid, temp->location);
		temp = temp->next;
	}
	save_locations(asm_main);
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
