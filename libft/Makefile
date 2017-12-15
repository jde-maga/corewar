#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 19:20:50 by mdamesto          #+#    #+#              #
#    Updated: 2017/03/20 22:16:04 by jde-maga         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC_PATH = ./src/
SRC_NAME =	ft_isascii.c ft_memcmp.c ft_strcmp.c ft_strncmp.c ft_toupper.c\
			ft_isdigit.c ft_memcpy.c ft_strcpy.c ft_strncpy.c ft_atoi.c\
			ft_isprint.c ft_memmove.c ft_strdup.c ft_strnstr.c ft_bzero.c\
			ft_memalloc.c ft_memset.c ft_strlcat.c ft_strrchr.c ft_isalnum.c\
			ft_memccpy.c ft_strcat.c ft_strlen.c ft_strstr.c ft_isalpha.c\
			ft_memchr.c ft_strchr.c ft_strncat.c ft_tolower.c ft_itoa.c\
			ft_putnbr_fd.c ft_striteri.c ft_strsub.c ft_memalloc.c ft_putstr.c\
			ft_strjoin.c ft_strtrim.c ft_memdel.c ft_putstr_fd.c ft_strmap.c\
			ft_putendl_fd.c ft_putchar.c ft_strclr.c ft_strmapi.c\
			ft_putchar_fd.c ft_strdel.c ft_strnequ.c ft_putendl.c ft_strequ.c\
			ft_strnew.c ft_putnbr.c ft_striter.c ft_strsplit.c ft_lstadd.c\
			ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_lstdel.c\
			ft_putnbr_base.c ft_itoa_base.c ft_itoa_base_u.c ft_ishex.c ft_strupper.c\
			get_next_line.c ft_str_isdigit.c ft_tab_realloc.c ft_tab_len.c ft_tab_free.c\
			ft_realloc.c ft_tab_print.c ft_tab_set.c ft_istr_set.c ft_itab_set.c\
			ft_itab_len.c ft_istrlen.c ft_strcut_beg.c ft_rmv_space.c ft_isspace.c ft_strsplit_space.c\
			ft_strcut_end.c ft_tab_join.c convert_hex_octnb.c fill_hex.c ft_tab_trim.c\
			ft_bin_to_int.c ft_is_label_char.c ft_strget.c ft_strcut.c ft_print_memory.c\
			ft_atoi_hex.c ft_size_long.c ft_size_int_binary.c ft_size_long.c ft_size_ulong.c\
			ft_strcat_uchar.c ft_strlen_ls.c ft_strlen_uchar.c ft_strnew_uchar.c ft_strrev.c\
			ft_itoa_long.c ft_atoi_long.c ft_atoi_short.c\
			utf_byte_size.c ft_isint.c ft_ispos.c ft_itoa_long.c ft_itoa_ulong.c\
			ft_printf.c string_parser.c ftprintf_struct_init.c next_arg_test.c\
			print_flags.c print_pad.c print_precision.c\
			parser_c.c print_c.c print_lc.c\
			parser_d.c print_d.c\
			parser_o.c print_o.c\
			parser_s.c print_s.c print_ls.c\
			parser_u.c print_u.c\
			parser_x.c print_x.c\
			parser_p.c print_p.c\
			print_utf_char.c

OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)

INC_PATH= ../inc/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))


all: $(NAME)

$(NAME): $(OBJ)
	@ar rcvsu $(NAME) $(OBJ)

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	rm -f $(OBJ)
	rmdir $(OBJ_PATH) 2>/dev/null || echo "" > /dev/null

fclean:	clean
	rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)
