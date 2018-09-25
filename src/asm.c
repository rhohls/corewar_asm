#include "../includes/asm.h"
#include <stdlib.h>

/*
**	len_to_char returns the index of the niddle on success
**	returns -1 if niddle not found
*/

char	*get_file_name(char *str)
{
	char	*name;
	char	*tmp;
	int		i;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	tmp = ft_strsub(str, 0, i + 1);
	name = ft_strjoin(tmp, "cor");
	free(tmp);
	return (name);
}

int		main(int argc, char *argv[])
{
	t_asm	*asm_main;
	int		fd;
	char	*name;

	if (argc == 2)
	{
		if (!correct_file(argv[1]))
			error_(0, "failed to open the file");
		initialize(&asm_main);
		asm_main->o_list = read_from_file(argv[1], &asm_main);
		// print_list(asm_main->o_list);
		parse_list(&asm_main);
		printf("\n\nnew lists\n\n");
		print_list(asm_main->n_commands);
		printf("\n\nnew label list\n\n");
		print_list(asm_main->n_labels);
		printf("\n\nFINAL list\n\n");
		print_list(asm_main->final_list);
		name = get_file_name(argv[1]);
		fd = open(name, O_RDWR | O_CLOEXEC | O_CREAT,S_IRWXU);
		//fd = open(name, O_CREAT | O_WRONLY);
		convert_code(asm_main, fd);
		close(fd);
	}
	else
		error_(0, "usage: need to pass a '.s' file as an argument");
	return 0;
}
