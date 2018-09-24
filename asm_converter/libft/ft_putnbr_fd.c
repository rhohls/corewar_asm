/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 10:17:20 by fledwaba          #+#    #+#             */
/*   Updated: 2018/05/26 13:20:19 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n >= -2147483647 && n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		c = '0' + (n % 10);
		write(fd, &c, 1);
	}
	else if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		c = '0' + n;
		write(fd, &c, 1);
	}
}
