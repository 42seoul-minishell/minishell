# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 11:35:24 by mingkim           #+#    #+#              #
#    Updated: 2022/10/05 16:57:40 by mingkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project File
NAME		= internal.a

# Compiler Flag and Command
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcusv

INC			= ../../include

DOUBLYDIR	= ./doublylist/
DOUBLY		= $(DOUBLYDIR)doubly.a

BTREEDIR	= ./btree/
BTREE		= $(BTREEDIR)btree.a

FILES		= internal \

SRCS_DIR	= ./
SRCS		= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR	= ./
OBJS		= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Main rule
all: 
	@make all -C $(DOUBLYDIR)
	@make all -C $(BTREEDIR)
	@echo "\033[92mBuild internal...\033[0m"
	@make $(NAME)

# Project file rule
$(NAME): $(OBJS) $(DOUBLY) $(BTREE)
	$(AR) $@ $?

# Make clean
clean:
	@echo "\033[92mClean internal files...\033[0m"
	rm -rf $(OBJS)
	make -C $(DOUBLYDIR) clean
	make -C $(BTREEDIR) clean

# Make fclean
fclean:
	@echo "\033[92mForce clean internal files...\033[0m"
	rm -rf $(OBJS)
	rm -rf $(NAME)
	make -C $(DOUBLYDIR) fclean
	make -C $(BTREEDIR) fclean

# Make re
re: 
	make fclean
	make all

.PHONY: all fclean clean re
