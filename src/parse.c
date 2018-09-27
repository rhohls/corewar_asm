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
		line_type(temp->data, &valid, asm_main);
		if (valid < 0)
		{
			command = sanitised_command(temp->line_no, (*asm_main)->n_commands);
			if (command != NULL)
			{
				size = (*(g_func_ptr[(valid * -1)]))(command->data, command->line_no, (*asm_main)->n_labels);
				if (size)
					command->size = size;
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
	t_asm_list	*commands;
	t_asm_list	*labels;
	int			size;

	commands = (*asm_main)->n_commands;
	labels = (*asm_main)->n_labels;
	size = 0;
	while (commands)
	{
		while (labels && labels->line_no <= commands->line_no)
		{
			set_label_loc(labels->line_no, size, labels);
			labels = labels->next;
		}
		set_command_loc(commands->line_no, size, commands);
		size += commands->size;
		commands = commands->next;
		if (!commands && labels)
		{
			while (labels)
			{
				set_label_loc(labels->line_no, size, labels);
				labels = labels->next;
			}
		}
	}
	(*asm_main)->comm_size = size;
	(*asm_main)->program_size = size;
}

int		label_lenght(char *str)
{
	int i;

	i = 0;
	while (ft_strchr(LABEL_CHARS ,str[i]) && str[i])
		i++;
	return (i);
}

char	*set_final_line(t_asm_list *node, t_asm_list *labels)
{
	char *ret;
	int i;
	size_t len;
	char *loc;
	t_asm_list *label;

	i = 0;
	label = labels;
	i = len_to_char(node->data, LABEL_CHAR);
	while (label)
	{
		if ((label_lenght(node->data + i + 1)  == (int)ft_strlen(label->data)) &&
		ft_strnequ(node->data + i + 1, label->data, ft_strlen(label->data)))
		{
			loc = ft_itoa(label->location - node->location);
			len = ft_strlen(node->data) - ft_strlen(label->data) + ft_strlen(loc);
			ret = ft_memalloc(len);
			ft_strncat(ret, node->data, i);
			ft_strcat(ret, loc);
			ft_strcat(ret, node->data + i + ft_strlen(label->data) + 1);
			free(loc);
			return (ret);
		}
		label = label->next;
	}
	return (NULL);
}

void	save_final_list(t_asm **asm_main)
{
	char		*line;
	t_asm_list	*temp;
	t_asm_list	*node;


	line = NULL;
	temp = (*asm_main)->n_commands;
	while (temp)
	{
		if (ft_strchr(temp->data, LABEL_CHAR))
			line = set_final_line(temp, (*asm_main)->n_labels);
		else
			line = ft_strdup(temp->data);
		node = new_final_node(line, temp);
		free(line);
		add_node_front(&((*asm_main)->final_list), node);
		temp = temp->next;
	}
}

void	set_comments_and_count(t_asm **asm_main, int name, int comment)
{
	if (name != 1 || comment != 1)
	{
		if (comment != 1 && name == 1)
			ft_strcat((*asm_main)->header->comment, "too lazy to comment\n");
		else
			error_(0, "check your header information");
	}
	save_sizes(asm_main);
	save_locations(asm_main);
	save_final_list(asm_main);
}

int	parse_list(t_asm **asm_main)
{
	int			valid;
	t_asm_list	*temp;
	int			test;
	int			name;
	int			comment;

	valid = 0;
	temp = (*asm_main)->o_list;
	name = 0;
	comment = 0;
	while (temp)
	{
		if ((test = line_type(temp->data, &valid, asm_main)) == 0)
			error_(temp->line_no, "invalid input on line : ");
		else if (valid == 3)
			save_label(temp->data, asm_main, &valid, temp->line_no);
		else if (valid == 1)
			name++;
		else if (valid == 2)
			comment++;
		else if (valid < 0)
			save_commands(temp->data, asm_main, &valid, temp->line_no);
		temp = temp->next;
	}
	set_comments_and_count(asm_main, name, comment);
	return (1);
}

int	line_type(char *line, int *valid, t_asm **asm_main)
{
	if (is_name(line, valid, asm_main))
		return (1);
	else if (is_comment(line, valid, asm_main))
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
