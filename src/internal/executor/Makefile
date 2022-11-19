# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 16:33:31 by mingkim           #+#    #+#              #
#    Updated: 2022/10/17 11:18:25 by mingkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project File
NAME			=	executor.a

# Compiler Flag and Command
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar rcsuv

INC				=	executor.h

FILES			=	executor \


SRCS_DIR		=	./
SRCS			=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR		=	./
OBJS			=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Main rule
all: 
	@echo "\033[92mBuild executor...\033[0m"
	@make $(NAME)

# Project file rule
$(NAME): $(OBJS)
	$(AR) $@ $?

# Make clean
clean:
	@echo "\033[92mClean executor files...\033[0m"
	rm -rf $(OBJS)

# Make fclean
fclean:
	@echo "\033[92mForce clean executor files...\033[0m"
	rm -rf $(OBJS)
	rm -rf $(NAME)

# Make re
re:
	make fclean
	make all

.PHONY: all fclean clean re