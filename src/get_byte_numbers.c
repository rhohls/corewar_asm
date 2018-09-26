#include "../includes/asm.h"

int			get_byte_no(char c)
{
	if (c == '%')
		return (4);
	else if (ft_isdigit(c))
		return (2);
	else if (c == 'r')
		return (1);
	else
		return (-1);
}

int			i_byte_no(char c)
{
	if (c == '%')
		return (2);
	else if (ft_isdigit(c))
		return (2);
	else if (c == 'r')
		return (1);
	else
		return (-1);
}