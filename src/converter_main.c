#include "../includes/asm.h"

void	
put(int fd, t_asm_list *h)
{
	t_asm_list	*t;

	t = h;
	while (t)
	{
		ft_putendl_fd(t->hex, fd);
		t = t->next;
	}
}

int converter_main(t_asm_list *list, char **av)
{
    t_asm_list *node;
    int i;
    char *str;

    i = 0;
    node = list;
    while (node)
	{
		if (ft_strstr(node->data, "live"))
			node->hex = live(node->data);
		else 
        if (ft_strstr(node->data, "lldi"))
			node->hex = lldi(node->data);
		else if (ft_strstr(node->data, "ldi"))
			node->hex = ldi(node->data);
		else if (ft_strstr(node->data, "lld"))
			node->hex = lld(node->data);
		else if (ft_strstr(node->data, "ld"))
			node->hex = ld(node->data);
		else if (ft_strstr(node->data, "sti"))
			node->hex = sti(node->data);
		else if (ft_strstr(node->data, "st"))
			node->hex = st(node->data);
		else if (ft_strstr(node->data, "add"))
			node->hex = add(node->data);
		else if (ft_strstr(node->data, "sub"))
			node->hex = sub(node->data);
		else if (ft_strstr(node->data, "and"))
			node->hex = and(node->data);
		else if (ft_strstr(node->data, "lfork"))
			node->hex = ft_lfork(node->data);
		else if (ft_strstr(node->data, "fork"))
			node->hex = ft_fork(node->data);
		else if (ft_strstr(node->data, "xor"))
			node->hex = xor(node->data);
		else if (ft_strstr(node->data, "or"))
			node->hex = or(node->data);
		else if (ft_strstr(node->data, "zjmp"))
			node->hex = zjmp(node->data);
		else if (ft_strstr(node->data, "aff"))
			node->hex = aff(node->data);
        node = node->next;
	}
	i = 0;
	while (av[1][i] && av[1][i] != '.')
		i++;
	str = ft_strsub(av[1], 0, i + 1);
	str = ft_strjoin(str, "cor");
	if ((i = open(str, O_CREAT | O_WRONLY)) < 0)
	{
		ft_putendl("no dude");
		return (0);
	}
	put(i, list);
    return (1);
}