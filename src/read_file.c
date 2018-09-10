/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 08:38:05 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/05 12:45:44 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <stdio.h> //remove

int		check_file_name(char *file_name)
{
	int i;

	i = ft_strlen(file_name);
	if (i < 3 || file_name[i - 1] != 's' || file_name[i - 2] != '.')
		return (0);
	return (100);
}

int	char_index(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int		check_header(t_header *champ, char *line)
{
	int 	i;
	int		j;
	char	*holder;


	if (ft_strncmp(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0)
	{
		/*
		**	Return 1 == something went wrong when trying to store the header --> name
		**	Return 2 == something went wrong when trying to store the header --> comment
		**	Return 100 == Everything went well
		*/
		i = ft_strlen(NAME_CMD_STRING);
		while ((line[i] == '\t' || line[i] == ' ') && line[i])
			i++;
		if (line[i] != '"')
			return (1);//error;
		else
		{
			i++;
			j = i;
			while (line[i] && ft_strchr(LABEL_CHARS, line[i]))
				i++;
			if (line[i] != '"')
				return (1); //;
		}
		/// store header
		holder = ft_strsub(line + j, 0, i - j);
		ft_strncat(champ->prog_name, holder, PROG_NAME_LENGTH + 1);
	}
	else if (ft_strncmp(line, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)) == 0)
	{
		i = ft_strlen(COMMENT_CMD_STRING);
		while ((line[i] == '\t' || line[i] == ' ') && line[i])
			i++;
		if (line[i] != '"')
			return (2);//error;
		else
		{
			i++;
			j = i;
			while (line[i] && (line[i] != '"') && i <= COMMENT_LENGTH)
				i++;
			if (line[i] != '"')
				return (2); //error;
		}
		/// store header
		holder = ft_strsub(line + j, 0, i - j);
		ft_strncat(champ->comment, holder, COMMENT_LENGTH + 1);
	}
	return (100);
}

int	check_line(char c)
{
	int i;

	i = 0;
	if (c == LABEL_CHAR || c == DIRECT_CHAR || c == SEPARATOR_CHAR)
		return (1);
	return (0);
}

int	store_clean_line(char *line, t_list **program)
{
	t_list	*temp;
	t_list	*node;
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (line[i] && (line[i] == '\t'|| line[i] == ' '))
		i++;
	if (line[i] == '#' || line[i] == '.' || line[i] == '\0')
		return (0);
	else
	{
		j = i;
		while (ft_strchr(LABEL_CHARS, line[i]) || line[i] == ' ' ||\
			line[i] == '\t' || check_line(line[i]))
			i++;
		if (line[i] == '#' || line[i])
			new = ft_strsub(line + j, 0, i - j);
	}
	temp = *program;
	
	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (0);
	//checking the lables and the commands, if they are all valid  before storing
	//calculate the size of the commands and store the number to content_size
	//add the node to the end of program
	node->content = new;
	node->content_size = 0;
	node->next = NULL;
	if (temp == NULL)
	{
		*program = node;
		return (1);
	}
	while (temp->next)
		temp = temp->next;
	temp->next = node;
	return (1);
}

int		is_it_whitespace(char c)
{
	if ((c == ' ') || (c == '\t'))
		return (1);
	return (0);
}

void	print_new_list(t_list *program)
{
	t_list *temp;

	temp = program;
	while (temp)
	{
		printf("--> %s\n", temp->content);
		temp = temp->next;
	}
}

int		is_label(char *line, int *n)
{
	int i;
	int	j;

	j = 0;
	i = char_index(line, ':');
	*n = i + 1;
	if (i)
	{
		//check if its a valid label
		if (line[i - 1] != '%')
		{
			while (is_it_whitespace(line[j]))
				j++;
			while (ft_strchr(LABEL_CHARS, line[j]) && (j < i))
				j++;
			if (i == j)
				return (1);
		}
	}
	return (0);
}

int		is_it_label(char *line, int *start)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	if (is_label(line, &i))
		ret = 1;
	else
		ret = 0;
	if (line[i])
		while (is_it_whitespace(line[i]))
			i++;
	*start = i;
	printf("is it label returning %d when line == %s\n", ret, line);
	return (ret);
}

void	store_label(char *line, int i, t_list **final)
{
	t_list	*node;
	int		index;

	index = 0;
	while (is_it_whitespace(line[index]))
		index++;
	node = ft_lstnew(line, 0);
	ft_lstaddfront(final, node);
}

void	store_line(char *line, int i, t_list **final)
{
	t_list	*node;

	while (is_it_whitespace(line[i]))
		i++;
	node = ft_lstnew(line, 0);
	ft_lstaddfront(final, node);
}

void	final_list(t_list *c_program, t_list **final)
{
	t_list	*c_temp;
	int		i;

	i = 0;
	c_temp = c_program;
	while (c_temp)
	{
		if (is_it_label(c_temp->content, &i))
		{
			printf("got in here-->final list\n");
			store_label(c_temp->content, i - 2, final);
			store_line(c_temp->content, i, final);
			//copy and store label and if index i, copy and store new line
		}
		else
		{
			//copy line from index i
			store_line(c_temp->content, i, final);  //testing
		}
		c_temp = c_temp->next;
	}
	print_new_list(*final);
}

int		parsing(char *file_name, t_asm *data, t_header *champ)
{
	int		ret;
	int		i;
	t_list	*temp;
	t_list	*final;
	/*
	**	the new clean list 
	*/
	t_list	*c_program;


	i = 0;
	c_program = NULL;
	final = NULL;
	temp = data->file_lines;
	while (temp)
	{
		//check line,
		if (((char*)temp->content)[0] != '\0' || ((char*)temp->content)[0] != COMMENT_CHAR)
		{
			while ((((char*)temp->content)[i] == '\t' || ((char*)temp->content)[i] == ' ') && \
				((char*)temp->content)[i])
				i++;
			
			//make sure to skip all comments starting with '#'
			if (((char*)temp->content)[i] == '#')
			{
				temp = temp->next;
				continue ;
			}
			//store name and comment
			if (((char*)temp->content)[i] == '.')
			{
				if ((ret = check_header(champ, ((char*)temp->content) + i)) != 100)
				{
					if (ret == 1)
						ft_putendl("Something went wrong: check .name");
					else if (ret == 2)
						ft_putendl("Something went wrong: check .comment");
					exit(0);
				}
			}
			store_clean_line(((char*)temp->content), &c_program);
		}
		temp = temp->next;
	}
	final_list(c_program, &final);
	//print_new_list(c_program);
	print_new_list(final);
	return (1);
}

void	read_file(char *file_name, t_asm *asm_data, t_header *champ)
{
	int fd;
	char	*line;
	int		gnl_ret;
	t_list	*temp;
	// fd = open(file_name, O_RDWR | O_CLOEXEC | O_CREAT,S_IRWXU); this is for writing

	fd = open(file_name, O_RDONLY);
	if (fd < 3 || (check_file_name(file_name) != 100))
	{
		ft_printf("Error: There was an error opening file \"%s\"\nReason: ", file_name);
		ft_putendl(strerror(errno));
		exit(0);
	}
	while ((gnl_ret = get_next_line(fd, &line)) == 1)
	{
		temp = ft_lstnew(line, ft_strlen(line) + 1);
		ft_lstaddfront(&(asm_data->file_lines), temp);
		free(line);
		line = NULL;
	}
	if (!parsing(file_name, asm_data, champ))
	{
		ft_putendl("Error reading data\n");
		exit(0);
	}
	if (gnl_ret == -1 || (gnl_ret == 0 && (asm_data->file_lines == NULL)))
	{
		ft_printf("Error reading data\n");
		exit(0);
	}
	
	t_list *node;
	
	node = asm_data->file_lines;
	while (node)
	{
		ft_printf("line: |%s|\n", node->content);
		node = node->next;
	}
}
