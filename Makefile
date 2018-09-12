# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/20 09:23:02 by swilson           #+#    #+#              #
#    Updated: 2018/09/11 19:24:12 by marvin           ###   ########.fr        #
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
SRC_NAME = asm.c error.c file.c init.c is_.c parse.c print.c save_.c string.c
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
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

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