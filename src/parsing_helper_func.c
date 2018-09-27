#include "../includes/asm.h"
#include <stdlib.h>

int	is_empty(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i])
		return (0);
	return (1);
}

int	is_valid_nbr(char *s, int sign)
{
	int		nbr;
	int		j;
	char	*number;
	char	*line;

	j = sign;
	while (ft_isdigit(s[j]))
		j++;
	line = ft_strsub(s, 0, j);
	nbr = ft_atoi(s);
	number = ft_itoa(nbr);
	if (ft_strequ(line, number))
		return (1);
	return (0);
}

int	check_register(char *str)
{
	int nbr;

	nbr = -123123;
	if (str[0] == 'r')
	{
		nbr = ft_atoi(str + 1);
		if ((nbr > 0) && (nbr < 17))
			return (1);
	}
	return (0);
}

int	check_indirect(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (!is_valid_nbr(str, i))
		return (0);
	return (1);
}

char	*copy_till_space(char *str)
{
	char	*ret;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (ft_strchr(LABEL_CHARS, str[len]))
		len++;
	ret = NULL;
	if (str[len] == ',')
		len--;
	if (!(ret = (char *)ft_memalloc(len + 1)))
		return (NULL);
	while ((str[i] != ' ') && str[i] && (str[i] != ',') && (str[i] != '\t'))
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int	is_valid_label(char *str, t_asm_list *labels)
{
	t_asm_list	*temp;
	char		*label;
	int			ret;

	label = copy_till_space(str);
	temp = labels;
	ret = 0;
	while (temp)
	{
		if (ft_strnequ(label, temp->data, ft_strlen(label)))
			ret = 1;
		temp = temp->next;
	}
	if (label != NULL)
		free(label);
	return (ret);
}

int	check_direct(char *str, t_asm_list *labels)
{
	int sign;

	sign = 0;
	if ((str[0] == '%') && (str[1] == LABEL_CHAR))
	{
		if (is_valid_label(str + 2, labels))
			return (1);
	}
	else if ((str[0] == '%') && (ft_isdigit(str[1]) || str[1] == '-'))
	{
		if (str[1] == '-')
			sign++;
		if (is_valid_nbr(str + 1, sign))
			return (1);
	}
	return (0);
}

int	check_r_d_i(char *str, t_asm_list *labels)
{
	if (check_register(str))
		return (1);
	if (check_direct(str, labels))
		return (2);
	else if (check_indirect(str))
		return (3);
	return (0);
}

int	check_r_d(char *str, t_asm_list *labels)
{
	if (check_register(str))
		return (1);
	else if (check_direct(str, labels))
		return (2);
	return (0);
}

int	check_r_i(char *str)
{
	if (check_register(str))
		return (1);
	else if (check_indirect(str))
		return (2);
	return (0);
}

int	check_d_i(char *str, t_asm_list *labels)
{
	if (check_direct(str, labels))
		return (1);
	if (check_indirect(str))
		return (2);
	return (0);
}
