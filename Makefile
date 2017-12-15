#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 19:20:50 by mdamesto          #+#    #+#              #
#    Updated: 2017/03/20 22:16:10 by jde-maga         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

ASM	=		./asm_src/
COREWAR	=	./corewar_src/
LIB	=		./libft/

#MAKE	=	make -C

all:
	$(MAKE)	-C $(LIB)
	$(MAKE) -C $(ASM)
	$(MAKE) -C $(COREWAR)

clean:
	$(MAKE)	-C $(LIB) clean
	$(MAKE) -C $(ASM) clean
	$(MAKE) -C $(COREWAR) clean

fclean:
	$(MAKE)	-C $(LIB) fclean
	$(MAKE) -C $(ASM) fclean
	$(MAKE) -C $(COREWAR) fclean

re:		fclean all

norme:
	$(MAKE)	-C $(LIB) norme
	$(MAKE) -C $(ASM) norme
	$(MAKE) -C $(COREWAR) norme

.PHONY:		re all fclean clean norme
.NOTPARALLEL:	re
