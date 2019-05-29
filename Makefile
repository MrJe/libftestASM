# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/18 18:09:15 by jmichaud          #+#    #+#              #
#    Updated: 2019/05/29 15:08:50 by gpoblon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
## V A R I A B L E S ###########################################################
# **************************************************************************** #
NAME			=	libftASM_tester

INC_DIR			=	./inc/
SRC_DIR			=	./src/
OBJ_DIR			=	./obj/
TRACE			=	../trace

SRC_NAME		=	\
					testception.c		\
					print.c				\
					launch_tests.c		\
					catch_signal.c		\
					test_bzero.c		\
					test_strcat.c		\
					test_isalnum.c		\
					test_isalpha.c		\
					test_isascii.c		\
					test_isdigit.c		\
					test_isprint.c		\
					test_tolower.c		\
					test_toupper.c		\
					test_isspace.c		\
					test_islower.c		\
					test_isupper.c		\
					test_puts.c			\
					test_strlen.c		\
					test_memset.c		\
					test_memcpy.c		\
					test_strdup.c		\
					test_cat.c			\
					main.c

################################################################################
## C O M P I L E R #############################################################
################################################################################
EXT				=	c
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
CPPFLAGS		=	-I$(INC_DIR)

LDFLAGS			=	-L../
LDLIBS			=	-lfts

################################################################################
## A U T O M A T I C ###########################################################
################################################################################
OBJ_NAME		=	$(SRC_NAME:.$(EXT)=.o)
OBJS			=	$(addprefix $(OBJ_DIR), $(OBJ_NAME))

################################################################################
## R U L E S ###################################################################
################################################################################
.PHONY			:	all clean fclean re

all				:	$(NAME)

$(NAME)			:	$(OBJ_DIR) $(OBJS) ../libfts.a
	$(CC) $(OBJS) -o $@ $(LDFLAGS) $(LDLIBS)
	touch $(TRACE) ../test_cat

$(OBJ_DIR)		:
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.$(EXT) Makefile | $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD $(CPPFLAGS) -c $< -o $@

clean			:
	rm -rf $(TRACE) ../test_cat
	@if [ -e $(OBJ_DIR) ]; then \
		rm -rf $(OBJ_DIR); \
		printf "rm -rf $(OBJ_DIR)\n"; \
	else \
		printf "make: Nothing to be done for 'clean'\n"; \
	fi;

fclean			:	clean
	rm -rf $(TRACE) ../test_cat
	rm -f $(NAME)

re				:	fclean
	make

-include $(OBJS:.o=.d)
