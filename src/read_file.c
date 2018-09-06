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

int		check_header(t_header *champ, char *line)
{
	int 	i;
	int		j;
	char	*holder;

	if (ft_strncmp(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
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
		printf("name = %s\n", holder);
		ft_strncat(champ->prog_name, holder, PROG_NAME_LENGTH + 1);
	}
	else if (ft_strncmp(line, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
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
			while (line[i] && ft_strchr(LABEL_CHARS, line[i]))
				i++;
			if (line[i] != '"')
				return (2); //error;
		}
		/// store header
		holder = ft_strsub(line + j, 0, i - j);
		printf("name = %s\n", holder);
		ft_strncat(champ->comment, holder, COMMENT_LENGTH + 1);
	}
	return (100);
}

int	store_clean_line(char *line, t_list *program)
{
	t_list *temp;
	t_list *node;

	temp = program;
	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (0);
	//checking the lables and the commands, if they are all valid  before storing
	//calculate the size of the commands and store the number to content_size
	//add the node to the end of program
	node->content = line;
	node->content_size = 0;
	node->next = NULL;
	if (temp == NULL)
	{
		program = node;
		return (1);
	}
	ft_putendl((char*)(temp->content));
	while (temp->next)
		temp = temp->next;
	temp->next = node;
	return (1);
}

int		parsing(char *file_name, t_asm *data, t_header *champ)
{
	int		ret;
	int		i;
	t_list	*temp;
	/*
	**	the new clean list 
	*/
	t_list	*c_program;


	i = 0;
	c_program = NULL;
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
			store_clean_line(((char*)temp->content) + i, c_program);
		}
		temp = temp->next;
	}
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
	if (fd < 3)// (check_file_name(file_name) == 100))
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
