# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bolee <bolee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 14:17:18 by bolee             #+#    #+#              #
#    Updated: 2022/12/13 14:17:19 by bolee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project File
NAME			=	libbuiltin.a
UNAME			= $(shell uname -s)

ifeq ($(UNAME), Linux)
READLINE_INC	=	/usr/include/readline
else
READLINE_INC	=	/Users/$(USER)/.brew/opt/readline/include
endif

# Compiler Flag and Command
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -I$(INC) -I$(READLINE_INC)
AR				=	ar rcsuv

INC				= 	../../../include
LIB_DIR			= 	../../../lib/

FILES			=	cd \
					echo \
					env \
					exit \
					export \
					pwd \
					unset

SRCS_DIR	=	./
SRCS		=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR	=	./
OBJS		=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Main rule
all: 
	@echo "\033[92mBuild builtin...\033[0m"
	@make $(NAME)

# Project file rule
$(NAME): $(OBJS)
	$(AR) $@ $?
	mv $(NAME) $(LIB_DIR)

# Make clean
clean:
	@echo "\033[92mClean builtin files...\033[0m"
	rm -rf $(OBJS)

# Make fclean
fclean:
	@echo "\033[92mForce clean builtin files...\033[0m"
	rm -rf $(OBJS)
	rm -rf $(NAME)

# Make re
re: 
	make fclean 
	make all

.PHONY: all fclean clean re
