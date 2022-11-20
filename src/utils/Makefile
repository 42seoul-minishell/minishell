# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 11:35:24 by mingkim           #+#    #+#              #
#    Updated: 2022/11/20 00:35:26 by gimmingyu        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project File
NAME		= utils.a

# Compiler Flag and Command
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcsuv

INC			= ../../include/minishell.h

FILES		= utils \
				verify_utils \
				tokenizer_utils

SRCS_DIR	= ./
SRCS		= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR	= ./
OBJS		= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Main rule
all: 
	@echo "\033[92mBuild utils...\033[0m"
	@make $(NAME)

# Project file rule
$(NAME): $(OBJS)
	$(AR) $@ $?

# Make clean
clean:
	@echo "\033[92mClean utils files...\033[0m"
	rm -rf $(OBJS)

# Make fclean
fclean: 
	@echo "\033[92mForce clean util files...\033[0m"
	rm -rf $(OBJS)
	rm -rf $(NAME)

# Make re
re: 
	make fclean
	make all

.PHONY: all fclean clean re
