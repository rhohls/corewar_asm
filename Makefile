# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swilson <swilson@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/20 09:23:02 by swilson           #+#    #+#              #
#    Updated: 2018/09/27 07:35:38 by swilson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
HDR_PATH = ./include/
INC_PATH = $(HDR_PATH) ./libft/
LIB_PATH = ./libft/
LIB_NAME = ./libft/libft.a

NAME = asm
HEADER = include/asm.h
SRC_NAME = asm.c error.c file.c init.c is_.c parse.c print.c save_.c string.c\
			test_files.c cw_add.c cw_aff.c cw_and.c cw_fork.c cw_ld.c cw_ldi.c\
			cw_null.c cw_live.c cw_lfork.c cw_lld.c cw_lldi.c cw_or.c cw_st.c\
			cw_sti.c cw_sub.c cw_xor.c cw_zjmp.c convert.c print_byte_list.c \
			add_asm_list.c long_atoi.c ld.c and.c or.c xor.c zjmp.c \
			ldi.c sti.c fork.c lld.c lldi.c lfork.c aff.c live.c st.c add.c \
			sub.c encodings.c convert_header.c clean_value.c get_byte_numbers.c\
			parsing_helper_func.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L,$(LIB_PATH))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/
	$(CC) $(LIB) $(LIB_NAME) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INCLUDE)
	mkdir -p $(OBJ_PATH)
	$(CC) $(INC) -o $@ -c $<

norm:
	norminette $(wordlist 1, 10, $(SRC))
	norminette $(wordlist 1, 2, $(HDR_PATH))
	make -C ./libft/ norm

clean:
	@make -C ./libft/ fclean
	@rm -rf $(OBJ) $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: norm clean fclean re
