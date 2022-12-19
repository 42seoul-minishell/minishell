# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bolee <bolee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 14:27:52 by bolee             #+#    #+#              #
#    Updated: 2022/12/13 14:27:53 by bolee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project File
NAME			=	libwildcard.a

ifeq ($(OS), Linux)
READLINE_INC	=	/usr/include/readline
else ($(OS), Darwin)
READLINE_INC	=	/Users/$(USER)/.brew/opt/readline/include
endif

# Compiler Flag and Command
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -I$(INC) -I$(READLINE_INC)
AR				=	ar rcsuv

INC				=	../../../include
LIB_DIR			=	../../../lib

FILES			=	wildcard \
					both_have \
					nothing_have \
					only_prefix \
					only_suffix \
					util

SRCS_DIR		=	./
SRCS			=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR		=	./
OBJS			=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

%.o: %.c
	$(CC) $(CFLAGS) -c $<  -o $@

# Main rule
all: 
	@echo "\033[92mBuild wildcard...\033[0m"
	@make $(NAME)

# Project file rule
$(NAME): $(OBJS)
	$(AR) $@ $?
	mv $(NAME) $(LIB_DIR)

# Make clean
clean:
	@echo "\033[92mClean wildcard files...\033[0m"
	rm -rf $(OBJS)

# Make fclean
fclean:
	@echo "\033[92mForce clean wildcard files...\033[0m"
	rm -rf $(OBJS)
	rm -rf $(NAME)

# Make re
re:
	make fclean
	make all

.PHONY: all fclean clean re
