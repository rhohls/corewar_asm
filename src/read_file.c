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


void	read_file(char *file_name, t_asm *asm_data)
{
	int fd;
	char	*line;
	int		gnl_ret;
	t_list	*temp;	
	// fd = open(file_name, O_RDWR | O_CLOEXEC | O_CREAT,S_IRWXU); this is for writing
	fd = open(file_name, O_RDONLY);
	if (fd < 3)
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
