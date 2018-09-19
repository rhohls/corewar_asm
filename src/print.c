#include "../includes/asm.h"
#include <stdlib.h>

void	print_list(t_asm_list *list)
{
	t_asm_list *temp;

	temp = list;
	while (temp)
	{
		ft_putstr(temp->data);
		ft_putstr("\t\t| ");
		ft_putnbr(temp->location);
		ft_putstr("\n");
		temp = temp->next;
	}
}