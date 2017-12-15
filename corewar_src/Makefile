#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/20 13:50:50 by jde-maga          #+#    #+#              #
#    Updated: 2017/03/20 22:15:48 by jde-maga         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = ../corewar

SRC_NAME = main.c inits.c file_parser.c get_variables.c cor_live.c cor_ld.c cor_st.c\
		cor_add.c cor_sub.c cor_and.c cor_or.c cor_xor.c cor_zjmp.c cor_ldi.c cor_sti.c cor_fork.c\
		cor_lld.c cor_lldi.c cor_lfork.c cor_aff.c endian_converter.c render.c argument_parser.c\
		operations.c live_check.c process_turn.c free_memory.c start_render.c
SRC_PATH = ./src/

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./obj/

LIB_PATH = ../libft
LIB_NAMES = -lft
INC_PATH = ../inc/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L,$(LIB_PATH))

CFLAGS = -Wall -Wextra -Werror
LDFLAGS = $(LIB) $(LIB_NAMES)
CC = gcc



all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(INC) -lncurses $^ -o $@ $(LDFLAGS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	rm -f $(OBJ)
	rmdir $(OBJ_PATH) 2>/dev/null || true

fclean: clean
	rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette ../inc/corewar.h

.PHONY: all clean fclean re norme
.NOTPARALLEL: re