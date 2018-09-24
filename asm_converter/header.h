/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:20:59 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/23 09:37:46 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
#include "./libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

typedef struct		s_asm
{
	char			*str;
	struct s_asm	*next;
}					t_asm;

void				add_asm_node(t_asm **h, char *line);

long long			long_atoi(const char *str);
long long       	clean_value(long long n);
char   				*hex(long long n, int bits);
int         		get_byte_no(char c);
int 		        i_byte_no(char c);

char      			*live(char *str);
char        		*ld(char *str);
char        		*st(char *str);
char        		*add(char *str);
char        		*sub(char *str);
char				*and(char *str);
char				*or(char *str);
char				*xor(char *str);
char				*zjmp(char *str);
char				*ldi(char *str);
char				*sti(char *str);
char       			*ft_fork(char *str);
char				*lld(char *str);
char				*lldi(char *str);
char				*ft_lfork(char *str);
char				*aff(char *str);

char				*check_and(char *str, int i, int j);
char				*check_ldi(char *str, int i, int j);
char				*check_lldi(char *str, int i, int j);
char				*check_or(char *str, int i, int j);
char				*check_sti(char *str, int i, int j);
char				*check_xor(char *str, int i, int j);

#endif
