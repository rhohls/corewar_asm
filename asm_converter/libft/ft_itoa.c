/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 07:40:52 by fledwaba          #+#    #+#             */
/*   Updated: 2018/08/07 10:14:49 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		num_dig(int n)
{
	int a;
	int num;

	if (n == 0)
		return (1);
	num = n;
	if (num < 0)
	{
		num = num * -1;
		a = 1;
	}
	else
		a = 0;
	while (num > 0)
	{
		num = num / 10;
		a++;
	}
	return (a);
}

static char		*min_v(void)
{
	char	*temp;

	temp = ft_strnew(ft_strlen("-2147483648"));
	if (!temp)
		return (NULL);
	ft_strcpy(temp, "-2147483648");
	return (temp);
}

static int		put(char *t, int n, int i)
{
	int a;

	a = n;
	if (a < 0)
		a = a * -1;
	while (a > 9)
	{
		t[i] = '0' + (a % 10);
		a = a / 10;
		i--;
	}
	t[i] = '0' + a;
	return (i);
}

char			*ft_itoa(int n)
{
	char	*t;
	int		i;

	if (n == -2147483648)
	{
		t = min_v();
		return (t);
	}
	i = num_dig(n);
	t = ft_strnew(i);
	if (!t)
		return (NULL);
	i--;
	i = put(t, n, i);
	if (i == 1)
	{
		i--;
		t[i] = '-';
	}
	return (t);
}
