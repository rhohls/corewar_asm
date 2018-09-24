# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/05 09:18:17 by fledwaba          #+#    #+#              #
#    Updated: 2018/09/23 09:38:27 by fledwaba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

OPR = ./operations/ld.c ./operations/and.c ./operations/or.c \
		./operations/xor.c ./operations/zjmp.c ./operations/ldi.c \
		./operations/sti.c ./operations/fork.c ./operations/lld.c \
		./operations/lldi.c ./operations/lfork.c ./operations/aff.c \
		./operations/live.c ./operations/st.c ./operations/add.c \
		./operations/sub.c ./operations/and_encoding.c \
		./operations/ldi_encoding.c ./operations/lldi_encoding.c \
		./operations/or_encoding.c ./operations/sti_encoding.c \
		./operations/xor_encoding.c


SRC = asm.c add_asm_list.c long_atoi.c hex.c

all:
	make -C ./libft
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) $(OPR) ./libft/libft.a

clean:
	make clean -C ./libft

fclean: clean
	make fclean -C ./libft

re: fclean all
