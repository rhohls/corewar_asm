#include "../include/asm.h"
#include <stdlib.h>

/*
**  after '%' check if its a valid number || valid :label
*/

/*
**  after 'r' check if its a valid number between 1 - 16
**	returns the len of the register on success
**	returns zero on failure
*/

/*
**  if its just a number, check if its a valid number
*/

// int    validate_register(char *line)
// {
// 	int i;

// 	i = 0;
// 	if (line[i] && ((line[i] <= 9) && (line[i] >= 0)))
// 	{
// 		i++;
// 		if (line[i] && ((line[i] <= 6) && (line[i] >= 0)))
// 			i++;
// 	}
// 	return (i);
// }

// int		validate_number(char *line)
// {
// 	int i;
// 	char *temp;
// 	char *temp2;
// 	int temp_nbr;

// 	i = 0;
// 	while (!line[i] || line[i] != ' ' && line[i] != ',')
// 		i++;
// 	temp = ft_strsub(line, 0, i);
// 	temp_nbr = ft_atoi(temp);
// 	temp2 = ft_itoa(temp_nbr);
// 	if (!ft_strequ(temp2, temp))
// 		i = 0;
// 	return (i);
// }

// int		validate_direct(char *line)
// {
// 	int i;

// 	i = 0;
// 	while (ft_strchr(LABEL_CHARS, line[i]))
// 		i++;
// 	if (line[i] == '\0' || line[i] == ' ' || line[i] == ',')
// 		return (i);
// 	return (0);
// }

// //this is how you use it
// //returns the no of args in the line
// //returns zero on failure
// int	parse_line(char *line)
// {
// 	int i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (ft_strchr(LINE_CHARS, line[i]))
// 	{
// 		if (line[i] == 'r')
// 		{
// 			printf("r i = %i\n", i);
// 			count++;
// 			if (!(i += validate_register(line + i + 1)))
// 				return (0);
// 			printf("r returning 1; i = %i\n", i);
// 		}
// 		else if (line[i] == '%')
// 		{
// 			printf("percentage i = %i\n", i);
// 			count++;
// 			if (!(i += validate_direct(line + i + 1)))
// 				return (0);
// 			printf("percentage returning 1; i = %i\n", i);
// 		}
// 		else if (line[i] == '-' || ft_isdigit(line[i]))
// 		{
// 			count++;
// 			if (!(i += validate_number(line + i)))
// 				return (0);
// 			printf("r returning 1; i = %i\n", i);
// 		}
// 			i++;
// 		printf("line i = %i , %c\n", i, line[i]);
// 	}
// 	while (is_white_space(line[i]))
// 		i++;
// 	if (!line[i] || line[i] == '#')
// 		return (count);
// 	return (0);
// }