/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 07:38:25 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/06 07:38:34 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char     convert(int n)
{
    if (n == 10)
        return ('a');
    else if (n == 11)
        return ('b');
    else if (n == 12)
        return ('c');
    else if (n == 13)
        return ('d');
    else if (n == 14)
        return ('e');
    else
        return ('f');
}

char    *hex(long long n, int bits)
{
    char    c;
    char    *str;
    int     s;
    int     i;
    int     f;

    s = bits + ((bits / 2) - 1);
    str = (char*)malloc(sizeof(char) * (s + 1));
    str[s] = '\0';
    i = s - 1;
    f = 1;
    while (n > 0)
    {
        s = n % 16;
        n = n / 16;
        if (s >= 10 && s <= 15)
            c = convert(s);
        else
            c = '0' + s;
        str[i] = c;
        i--;
        if (f == 2)
        {
            str[i] = ' ';
            i--;
            f = 1;
        }
        else
            f++;
    }
    if (f == 2)
    {
        str[i] = '0';
        i--;
        str[i] = ' ';
        i--;
    }
    f = 1;
    while (i >= 0)
    {
        str[i] = '0';
        i--;
        if (f == 2)
        {
            str[i] = ' ';
            i--;
            f = 1;
        }
        else
            f = 2;
    }
    return (str);
}

long long       clean_value(long long n)
{
    int     nu;
    if (n < -2147483648)
        nu = (2147483647 + (n + 2147483648)) + 1;
    else if (n > 2147483647)
        nu = ((n - 2147483647) + -2147483648) -1;
    else
        nu = n;
    if (nu >=  -2147483648 && nu < 0)
        n = 2147483647 + (nu + 2147483648) + 1;
    else
        n = nu;
    return (n);

}
/*
int        main(int i, char **v)
{
    char    *str;
    long long   n;
    
    n = clean_value(long_atoi(v[1]));    
    str = hex(n, 8);
    ft_putendl(str);
    return (0);
}*/