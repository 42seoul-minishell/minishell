# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 11:35:24 by mingkim           #+#    #+#              #
#    Updated: 2022/10/05 12:52:11 by mingkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project File
NAME = internal.a

# Compiler Flag and Command
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

INC = ../../include

FILES = internal \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Main rule
all : 
	@echo "\033[92mBuild internal...\033[0m"
	@make $(NAME)

# Project file rule
$(NAME) : $(OBJS)
	$(AR) $@ $?

# Make clean
clean:
	@echo "\033[92mClean internal files...\033[0m"
	rm -rf $(OBJS)

# Make fclean
fclean: 
		@echo "\033[92mForce clean internal files...\033[0m"
		rm -rf $(OBJS)
		rm -rf $(NAME)

# Make re
re: fclean all

.PHONY: all fclean clean re
