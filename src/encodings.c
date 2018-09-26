#include "../includes/asm.h"

int			check_sti(char *str, int i, int j)
{
	if (str[i] == '%' && str[j] == '%')
		return (104); //s = ft_strdup("0b 68 ");
	else if (str[i] == '%' && str[j] == 'r')
		return (100); //s = ft_strdup("0b 64 ");
	else if (ft_isdigit(str[i]) && str[j] == '%')
		return (120); //s = ft_strdup("0b 78 ");
	else if (ft_isdigit(str[i]) && str[j] == 'r')
		return (116); //s = ft_strdup("0b 74 ");
	else if (str[i] == 'r' && str[j] == '%')
		return (132); //s = ft_strdup("0b 84 ");
	else if (str[i] == 'r' && str[j] == 'r')
		return (84); //s = ft_strdup("0b 54 ");
	return (-1);
}

int			check_encoding_byte(char *str, int i, int j)
{
	if (str[i] == '%' && str[j] == '%')
		return (164); //s = ft_strdup("0e a4 ");
	else if (str[i] == '%' && ft_isdigit(str[j]))
		return (180); //s = ft_strdup("0e b4 ");
	else if (str[i] == '%' && str[j] == 'r')
		return (148); //s = ft_strdup("0e 94 ");
	else if (ft_isdigit(str[i]) && str[j] == '%')
		return (228); //s = ft_strdup("0e e4 ");
	else if (ft_isdigit(str[i]) && ft_isdigit(str[j]))
		return (244); //s = ft_strdup("0e f4 ");
	else if (ft_isdigit(str[i]) && str[j] == 'r')
		return (212); //s = ft_strdup("0e d4 ");
	else if (str[i] == 'r' && str[j] == '%')
		return (100); //s = ft_strdup("0e 64 ");
	else if (str[i] == 'r' && ft_isdigit(str[j]))
		return (116); //s = ft_strdup("0e 74 ");
	else if (str[i] == 'r' && str[j] == 'r')
		return (84); //s = ft_strdup("0e 54 ");
	return (-1);
}