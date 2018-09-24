#include "../includes/asm.h"
#include <stdlib.h>

void	print_list(t_asm_list *list)
{
	t_asm_list *temp;

	temp = list;
	while (temp)
	{
		ft_putstr(temp->data);
		ft_putstr("\t| ");
		ft_putnbr(temp->line_no);
		ft_putstr("\t| ");
		ft_putnbr(temp->location);
		ft_putstr("\t| ");
		ft_putnbr(temp->size);
		ft_putstr("\t|");
		ft_putstr(temp->hex);
		ft_putstr("\n");
		temp = temp->next;
	}
}