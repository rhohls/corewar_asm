/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 10:20:07 by swilson           #+#    #+#             */
/*   Updated: 2018/09/12 14:33:09 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "../libft/get_next_line.h"
# include "op.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

typedef struct			s_asm_list
{
	char				*data;
	int					location;
	struct s_asm_list	*next;
}						t_asm_list;

typedef struct			s_asm
{
	t_header			*header;
	t_asm_list			*o_list;
	t_asm_list			*n_commands;
	t_asm_list			*n_labels;
}						t_asm;

void					exit_str(char *str);
int						error_(int line_no, char *output);
int 					correct_file(const char *file);
t_asm_list				*read_from_file(char *file_name, t_asm **asm_main);
void					initialize(t_asm **asm_main);
char					**init_commands(void);
t_asm_list				*new_node(char *line, int pos);
void					add_node_front(t_asm_list **head, t_asm_list *node);
int						is_name(char *line, int *valid);
int						is_label(char *line, int *valid);
int						is_comment(char *line, int *valid);
int						is_command(char *line, int *valid);
int						parse_list(t_asm **asm_main);
int						line_type(char *line, int *valid);
int						balancing_quotations(char *line);
void					print_list(t_asm_list *list);
void					save_commands(char *str, t_asm **asm_main, int *valid);
void					save_label(char *str, t_asm **asm_main, int *valid);
int						len_to_char(char *s, int c);
int						is_white_space(char c);
int						is_blank(char *line, int *valid);
int						comments(char *line, int *valid);

/*
** Functions
*/

int		cw_null(char *str);
int		cw_live(char *str);
int		cw_ld(char *str);
int		cw_st(char *str);
int		cw_add(char *str);
int		cw_sub(char *str);
int		cw_and(char *str);
int		cw_or(char *str);
int		cw_xor(char *str);
int		cw_zjmp(char *str);
int		cw_ldi(char *str);
int		cw_sti(char *str);
int		cw_fork(char *str);
int		cw_lld(char *str);
int		cw_lldi(char *str);
int		cw_lfork(char *str);
int		cw_aff(char *str);

#endif
