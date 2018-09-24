/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 10:20:07 by swilson           #+#    #+#             */
/*   Updated: 2018/09/21 12:24:55 by swilson          ###   ########.fr       */
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
	char				*hex;
	int					location;
	int					size;
	int					line_no;
	struct s_asm_list	*next;
}						t_asm_list;

typedef struct			s_asm
{
	t_header			*header;
	t_asm_list			*o_list;
	t_asm_list			*n_commands;
	t_asm_list			*n_labels;
	t_asm_list			*final_list;
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
void					save_commands(char *str, t_asm **asm_main, int *valid, int loc);
void					save_label(char *str, t_asm **asm_main, int *valid, int n);
int						len_to_char(char *s, int c);
int						is_white_space(char c);
int						is_blank(char *line, int *valid);
int						comments(char *line, int *valid);
int						is_valid_nbr(char *s, int sign);
int						check_register(char *str);
int						check_indirect(char *str);
char					*copy_till_space(char *str);
int						is_valid_label(char *str, t_asm_list *labels);
int						check_direct(char *str, t_asm_list *labels);
int						check_r_d_i(char *str, t_asm_list *labels);
int						check_r_d(char *str, t_asm_list *labels);
int						check_r_i(char *str);
int						check_d_i(char *str, t_asm_list *labels);
t_asm_list				*new_final_node(char *line, t_asm_list *command);

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
void	adjust_ret(int *ret, int j, int *i, int hold, char *str);

static int (*g_func_ptr[17])(char *str, int loc, t_asm_list *labels) =
{
    cw_null, cw_ld, cw_st, cw_add, cw_sub, cw_and, cw_or,
    cw_xor, cw_zjmp, cw_ldi, cw_sti, cw_fork, cw_lld, cw_lldi,
    cw_lfork, cw_aff, cw_live
};

/*
**	converter functions
*/
int					converter_main(t_asm_list *list, char **av);
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
