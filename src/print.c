#include "../include/asm.h"
#include <stdlib.h>

void	print_list(t_asm_list *list)
{
	t_asm_list *temp;

	temp = list;
	while (temp)
	{
		ft_putendl(temp->data);
		temp = temp->next;
	}
}