/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/21 14:22:18 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

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
	// printf("str: %s - str[0] |%c|   -   nbr %d\n", str, str[0], nbr);
	return (0);
}

int	check_indirect(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
// printf("check indirect str = |%s| i = %d\n", str, i);
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
	//  printf("len = %d\n", len);
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
	// printf("str = %s vs %s\n", str, labels->data);
	label = copy_till_space(str);
	// ft_putendl("after copy till space");
	temp = labels;
	// printf("label = %s\n", label);
	ret = 0;
	// ft_putstr("before sev\n");
	// ft_putstr(label);
	// ft_putstr("before sev\n");
	while (temp)
	{
		// ft_putstr(label);
		// ft_putstr(" vs ");
		// ft_putstr(temp->data);
		// ft_putchar('\n');
		// printf("label len =%lu\n", ft_strlen(label));
		if (ft_strnequ(label, temp->data, ft_strlen(label)))
			ret = 1;
		// printf("returning %d\n", ret);
		temp = temp->next;
	}
	if (label != NULL)
		free(label);
	// ft_putnbr(ret);
	return (ret);
}

int	check_direct(char *str, t_asm_list *labels)
{
	int sign;

	// ft_putendl("checking direct");
	// ft_putendl(str);
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

// cw_sti:Y ***sti D=2 (not 4)
// 		RRR		5
// 		RIR		6
// 		RDR		6
// 		RRD		6
// 		RID		7
// 		RDD		7

int	cw_sti(char *str, int loc, t_asm_list *labels)
{
	int i;
	int j;
	int ret;
	int hold;
// printf("in sti===============================>\n");
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
		// printf("str = %s\n", str + i);
		if ((hold = check_r_d_i(str + i, labels)) > 0)
		{
			j = len_to_char(str + i, ' ');
			i += j;
			i++;
			if (hold == 1)
				ret += 1;
			else// if ((hold == 2) || (hold == 3))
				ret += 2;
				// printf("ret == %d\n", ret);
			if ((hold = check_r_d(str + i, labels)) > 0)
					return (ret + hold);
		}
	}
	error_(loc, "check the format on line : ");
	return (0);
}