/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/20 10:26:23 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	is_valid_nbr(char *s)
{
	int		nbr;
	int		j;
	char	*number;
	char	*line;

	j = 0;
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
	if (!is_valid_nbr(str))
		return (0);
	return (1);
}

char	*copy_till_space(char *str)
{
	char	*ret;
	int		i;
	int		len;

	i = 0;
	len = len_to_char(str, ' ');
	ret = NULL;
	if (str[len] == ',')
		len--;
	if (!(ret = (char *)ft_memalloc(len + 1)))
		return (NULL);
	while ((str[i] != ' ') && str[i] && (str[i] != ','))
	{
		ret[i] = str[i];
		i++;
	}
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
	ft_putnbr(ret);
	return (ret);
}

int	check_direct(char *str, t_asm_list *labels)
{
	if ((str[0] == '%') && (str[1] == LABEL_CHAR))
	{
		if (is_valid_label(str + 2, labels))
			return (1);
	}
	else if ((str[0] == '%') && (ft_isdigit(str[1])))
	{
		if (is_valid_nbr(str + 1))
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

int	cw_sti(char *str, int loc, t_asm_list *labels)
{
	int i;
	int j;
	int ret;
	int hold;

	i = 0;
	ret = 2;
	while (is_white_space(str[i]))
		i++;
	i += 4;
	if (check_register(str + i))
	{
		ret += 1;
		j = len_to_char(str, ',');
		i = (str[j + 1] == ' ') ? j + 2 : j + 1;
		if ((hold = check_r_d_i(str + i, labels)) > 0)
		{
			j = len_to_char(str + i, ' ');
			i += j;
			i++;
			if (hold == 1)
				ret += 1;
			else if ((hold == 2) || (hold == 3))
				ret += 2;
			if ((hold = check_r_d(str + i, labels)) > 0)
					return (ret + hold);
		}
	}
	error_(loc, "check the format on line : ");
	return (0);
}