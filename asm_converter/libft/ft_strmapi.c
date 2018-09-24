/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 08:42:07 by fledwaba          #+#    #+#             */
/*   Updated: 2018/05/26 15:45:14 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*t;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	t = (char*)malloc((i + 1));
	if (!t)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		t[i] = (*f)(i, s[i]);
		i++;
	}
	t[i] = '\0';
	return (t);
}
