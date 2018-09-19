/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 10:20:07 by swilson           #+#    #+#             */
/*   Updated: 2018/09/18 09:43:49 by swilson          ###   ########.fr       */
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
# define LINE_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789 ,%:-"


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
int						parse_list(t_asm **asm_main, int len);
int						line_type(char *line, int *valid);
int						balancing_quotations(char *line);
void					print_list(t_asm_list *list);
void					save_commands(char *str, t_asm **asm_main, int *valid, int loc);
void					save_label(char *str, t_asm **asm_main, int *valid, int n);
int						len_to_char(char *s, int c);
int						is_white_space(char c);
int						is_blank(char *line, int *valid);
int						comments(char *line, int *valid);
int	is_valid_nbr(char *s);
int	check_register(char *str);
int	check_indirect(char *str);
char	*copy_till_space(char *str);
int	is_valid_label(char *str, t_asm_list *labels);
int	check_direct(char *str, t_asm_list *labels);
int	check_r_d_i(char *str, t_asm_list *labels);
int	check_r_d(char *str, t_asm_list *labels);
int	check_d_i(char *str, t_asm_list *labels);
/*
** Functions
*/

int		cw_null(char *str, int loc, t_asm_list *labels);
int		cw_live(char *str, int loc, t_asm_list *labels);
int		cw_ld(char *str, int loc, t_asm_list *labels);
int		cw_st(char *str, int loc, t_asm_list *labels);
int		cw_add(char *str, int loc, t_asm_list *labels);
int		cw_sub(char *str, int loc, t_asm_list *labels);
int		cw_and(char *str, int loc, t_asm_list *labels);
int		cw_or(char *str, int loc, t_asm_list *labels);
int		cw_xor(char *str, int loc, t_asm_list *labels);
int		cw_zjmp(char *str, int loc, t_asm_list *labels);
int		cw_ldi(char *str, int loc, t_asm_list *labels);
int		cw_sti(char *str, int loc, t_asm_list *labels);
int		cw_fork(char *str, int loc, t_asm_list *labels);
int		cw_lld(char *str, int loc, t_asm_list *labels);
int		cw_lldi(char *str, int loc, t_asm_list *labels);
int		cw_lfork(char *str, int loc, t_asm_list *labels);
int		cw_aff(char *str, int loc, t_asm_list *labels);

static int (*g_func_ptr[17])(char *str, int loc, t_asm_list *labels) =
{// return int = amnt of jumps needed by pc ??/
    cw_null, cw_live, cw_ld, cw_st, cw_add, cw_sub, cw_and, cw_or,
    cw_xor, cw_zjmp, cw_ldi, cw_sti, cw_fork, cw_lld, cw_lldi,
    cw_lfork, cw_aff
};
#endif
