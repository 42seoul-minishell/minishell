# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bolee <bolee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 14:16:14 by bolee             #+#    #+#              #
#    Updated: 2022/12/13 14:16:15 by bolee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project File
NAME		= error.a

# Compiler Flag and Command
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcsuv

INC			= ../../include/minishell.h

FILES		= error \

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
