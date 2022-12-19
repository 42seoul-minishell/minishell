# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 11:13:33 by mingkim           #+#    #+#              #
#    Updated: 2022/10/17 11:40:53 by mingkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project File
NAME			=	testBuiltin
UNAME			= $(shell uname -s)

# Compiler Flag and Command
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -I$(INC)

# Debugging Flag
DEBUG			=	-g

# Project sources, includes, builds
BUILTIN_DIR		=	../../src/internal/builtin
DOUBLY			=	$(BUILTIN_DIR)/builtin.a

INC				=	../../include/
LIBFT_DIR		=	$(INC)libft/
LIBFT			=	$(LIBFT_DIR)libft.a

FILES			=	main \

SRCS_DIR		=	./
SRCS			=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR		=	./
OBJS			=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

# Project file rule
$(NAME): $(OBJS)
	@make all -C $(LIBFT_DIR)
	@make all -C $(BUILTIN_DIR)
	@echo "\033[92mBuild test for builtin methods...\033[0m"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(DOUBLY) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC) -I$(DOUBLY) -I$(LIBFT) -c $< -o $@

# Main rule
all:
	make $(NAME)

# Make clean
clean:
	@echo "\033[92mClean test files...\033[0m"
	rm -rf $(OBJS)
	make -C $(BUILTIN_DIR) clean
	make -C $(LIBFT_DIR) clean

# Make fclean
fclean: 
	@echo "\033[92mForce clean test files...\033[0m"
	rm -rf $(OBJS)
	rm -rf $(NAME)
	make -C $(BUILTIN_DIR) fclean
	make -C $(LIBFT_DIR) fclean

# Make re
re: 
	make fclean
	make all

.PHONY: all fclean clean re
