#include "../includes/asm.h"
#include <stdlib.h>

t_asm_list	*sanitised_command(int loc, t_asm_list *list)
{
	t_asm_list *commands;

	commands = list;
	while (commands)
	{
		if (commands->line_no == loc)
			return (commands);
		commands = commands->next;
	}
	return (NULL);
}

void	save_sizes(t_asm **asm_main)
{
	t_asm_list	*temp;
	t_asm_list	*command;
	t_asm_list	*labels;
	int			size;
	int			valid;

	temp = (*asm_main)->n_commands;
	labels = (*asm_main)->n_labels;
	while (temp)
	{
		// printf("looking at ==> %s\n", temp->data);
		line_type(temp->data, &valid);
		if (valid < 0)
		{
			command = sanitised_command(temp->line_no, (*asm_main)->n_commands);
			if (command != NULL)
			{
				// printf("~~input string |%s| line no: %d \n",command->data, command->line_no );
				// printf("calling function number: %d~~\n", valid * -1);
				size = (*(g_func_ptr[(valid * -1)]))(command->data, command->line_no, (*asm_main)->n_labels);
				if (size)
					command->size = size;
				// printf("size ======>%d\n", size);
			}
		}
		temp = temp->next;
	}
}

void	set_label_loc(int line_num, int pos, t_asm_list *labels)
{
	t_asm_list *temp;

	temp = labels;
	while (temp)
	{
		if (temp->line_no == line_num)
			temp->location = pos;
		temp = temp->next;
	}
}

void	set_command_loc(int line_num, int pos, t_asm_list *commands)
{
	t_asm_list *temp;

	temp = commands;
	while (temp)
	{
		if (temp->line_no == line_num)
			temp->location = pos;
		temp = temp->next;
	}
}


void	save_locations(t_asm **asm_main)
{
	t_asm_list	*temp;
	int			size;

	temp = (*asm_main)->n_commands;
	size = 0;
	while (temp)
	{
		set_label_loc(temp->line_no, size, (*asm_main)->n_labels);
		set_command_loc(temp->line_no, size, (*asm_main)->n_commands);
		size += temp->size;
		temp = temp->next;
	}
}

int	parse_list(t_asm **asm_main, int len)
{
	int			valid;
	t_asm_list	*temp;
	int			test;
	int			name;
	int			comment;

	valid = 0;
	temp = (*asm_main)->o_list;
	len = 0;
	name = 0;
	comment = 0;
	while (temp)
	{
		if ((test = line_type(temp->data, &valid)) == 0)
			error_(temp->line_no, "invalid input on line : ");
		if (valid == 3)
			save_label(temp->data, asm_main, &valid, temp->line_no);
		if (valid == 1)
			name++;
		if (valid == 1)
			comment++;
		else if (valid < 0)
			save_commands(temp->data, asm_main, &valid, temp->line_no);
		temp = temp->next;
	}
	if (name != 1 || comment != 1)
		error_(0, "check your header information");
	// printf("\nBefore saving locations, from parser\n");
	// print_list((*asm_main)->n_commands);
	// printf("\nEnd\n\n");
	save_sizes(asm_main);
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
