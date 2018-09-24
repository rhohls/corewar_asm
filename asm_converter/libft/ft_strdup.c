/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 08:11:18 by fledwaba          #+#    #+#             */
/*   Updated: 2018/05/25 15:38:47 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*s1;
	int			i;

	i = ft_strlen(s);
	s1 = (char*)malloc(i + 1);
	if (s1 == NULL)
		return (NULL);
	s1 = ft_strcpy(s1, s);
	return (s1);
}
