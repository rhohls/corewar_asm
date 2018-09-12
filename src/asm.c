#include "../include/asm.h"
#include <stdlib.h>

/*
**	len_to_char returns the index of the niddle on success
**	returns -1 if niddle not found
*/

int main(int argc, char *argv[])
{
	t_asm	*asm_main;

	if (argc == 2)
	{
		if (!correct_file(argv[1]))
			error_(0, "failed to open the file");
		initialize(&asm_main);
		asm_main->o_list = read_from_file(argv[1], &asm_main);
		print_list(asm_main->o_list);
		parse_list(&asm_main);
	}
	else
		error_(0, "usage: need to pass a '.s' file as an argument");
	return 0;
}
