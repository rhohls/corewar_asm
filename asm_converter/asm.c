/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:10:19 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/05 12:12:18 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_list(t_asm *h)
{
	t_asm	*t;

	t = h;
	while (t)
	{
		ft_putendl(t->str);
		t = t->next;
	}
}

void	put(int fd, t_asm *h)
{
	t_asm	*t;

	t = h;
	while (t)
	{
		ft_putendl_fd(t->str, fd);
		t = t->next;
	}
}

int		main(int n, char **v)
{
	int		i;
	t_asm	*h;
	char	*line;
	char	*str;

	(void)n;
	if ((i = open(v[1], O_RDONLY)) < 0)
	{
		ft_putendl("Error, cant open file");
		return (0);
	}
	while (get_next_line(i, &line))
	{
		if (ft_strstr(line, "live"))
			add_asm_node(&h, live(line));
		else if (ft_strstr(line, "lldi"))
			add_asm_node(&h, lldi(line));
		else if (ft_strstr(line, "ldi"))
			add_asm_node(&h, ldi(line));
		else if (ft_strstr(line, "lld"))
			add_asm_node(&h, lld(line));
		else if (ft_strstr(line, "ld"))
			add_asm_node(&h, ld(line));
		else if (ft_strstr(line, "sti"))
			add_asm_node(&h, sti(line));
		else if (ft_strstr(line, "st"))
			add_asm_node(&h, st(line));
		else if (ft_strstr(line, "add"))
			add_asm_node(&h, add(line));
		else if (ft_strstr(line, "sub"))
			add_asm_node(&h, sub(line));
		else if (ft_strstr(line, "and"))
			add_asm_node(&h, and(line));
		else if (ft_strstr(line, "lfork"))
			add_asm_node(&h, ft_lfork(line));
		else if (ft_strstr(line, "fork"))
			add_asm_node(&h, ft_fork(line));
		else if (ft_strstr(line, "xor"))
			add_asm_node(&h, xor(line));
		else if (ft_strstr(line, "or"))
			add_asm_node(&h, or(line));
		else if (ft_strstr(line, "zjmp"))
			add_asm_node(&h, zjmp(line));
		else if (ft_strstr(line, "aff"))
			add_asm_node(&h, aff(line));
		free(line);
	}
	i = 0;
	while (v[1][i] && v[1][i] != '.')
		i++;
	str = ft_strsub(v[1], 0, i + 1);
	str = ft_strjoin(str, "cor");
	if ((i = open(str, O_CREAT | O_WRONLY)) < 0)
	{
		ft_putendl("no dude");
		return (0);
	}
	put(i, h);
	return (0);
}
