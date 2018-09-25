/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_byte_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 09:17:34 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/24 09:17:37 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void        print_byte_list(t_byte *h)
{
    t_byte  *t;

    t = h;
    ft_putendl("\nlist:");
    while (t)
    {
        ft_putendl(t->str);
        t = t->next;
    }
}
