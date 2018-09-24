/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:57:29 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/10 15:57:42 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char        *zjmp(char *str)
{
    int             i;
    long long       n;
    char            *s;
    char            *t;

    i = 0;
    while (str[i] && str[i] != '%')
        i++;
    if (str[i] == '\0')
        return (NULL);
    i++;
    n = long_atoi(&str[i]);
    n = clean_value(n);
    t = hex(n, 4);
    s = ft_strjoin("09 ", t);
    //free
    return (s);
}