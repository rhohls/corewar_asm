#include "../includes/asm.h"
#include <stdlib.h>

int	save_header_name(char *line, t_asm **asm_main)
{
	int i;

	i = 0;
	printf("name saved here\n");
	if ((ft_strlen(line) - 1) > PROG_NAME_LENGTH)
		error_(0, "name too long");
	while ((line[i] != '"') && line[i])
	{
		(*asm_main)->header->prog_name[i] = line[i];
		i++;
	}
	printf("\n%s\n\n", (*asm_main)->header->prog_name);
	printf("done saving name");
	return (1);
}

int	save_header_comment(char *line, t_asm **asm_main)
{
	int i;

	printf("comment saved here\n");
	i = 0;
	if ((ft_strlen(line) - 1) > COMMENT_LENGTH)
		error_(0, "comment too long");
	while ((line[i] != '"') && line[i])
	{
		(*asm_main)->header->comment[i] = line[i];
		i++;
	}
	return (1);
}

int	is_name(char *line, int *valid, t_asm **asm_main)
{
	int i;
	int j;

	i = len_to_char(line, '.');
	if (line[i] == '.')
	{
		if (!ft_strnequ(line + i, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
			return (0);
		j = i - 1;
		while (j >= 0 && is_white_space(line[i]))
			j--;
		if (j > -1)
			return (0);
		i = i + ft_strlen(NAME_CMD_STRING);
		while (line[i] && is_white_space(line[i]))
			i++;
		if (balancing_quotations(line + i))
		{
			*valid = 1;
			save_header_name(line + 1 + i, asm_main);
			printf("line = %s\n", line + i + 1);
			return (1);
		}
	}
	return (0);
}

int	is_label(char *line, int *valid)
{
	int i;
	int j;

	i = 0;
	j = len_to_char(line, LABEL_CHAR);
	if (j == -1)
		return (0);
	while (is_white_space(line[i]))
		i++;
	while (ft_strchr(LABEL_CHARS, line[i]))
		i++;
	if (i != j)
		return (0);
	*valid = 3;
	return (1);
}

int	is_comment(char *line, int *valid, t_asm **asm_main)
{
	int i;
	int j;

	i = len_to_char(line, '.');
	if (line[i] == '.')
	{
		if (!ft_strnequ(line + i, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
			return (0);
		j = i - 1;
		while (j >= 0 && is_white_space(line[i]))
			j--;
		if (j > -1)
			return (0);
		i = i + ft_strlen(COMMENT_CMD_STRING);
		while (line[i] && is_white_space(line[i]))
			i++;
		if (balancing_quotations(line + i))
		{
			save_header_name(line + 1 + i, asm_main);
			*valid = 2;
			return (1);
		}
	}
	return (0);
}

int	is_command(char *line, int *valid)
{
	char	**commands;
	int		i;
	int		j;
	int		flag;

	commands = init_commands();
	j = 0;
	i = 0;
	flag = -1;
	while (is_white_space(line[j]))
		j++;

	while (++i <= 16)
	{
		if (ft_strnequ(line + j, commands[i], ft_strlen(commands[i])))
			flag = i;
	}
	if (flag > -1)
	{
		*valid = flag * -1;
		return (1);
	}
	return (0);
}
