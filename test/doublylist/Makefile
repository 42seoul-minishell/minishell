# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 11:13:33 by mingkim           #+#    #+#              #
#    Updated: 2022/10/07 12:49:05 by mingkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project File
NAME			=	testDoublyList

# Compiler Flag and Command
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -I$(INC)

# Debugging Flag
DEBUG			=	-g

# Project sources, includes, builds
DOUBLY_DIR		=	../../src/internal/doublylist
DOUBLY			=	$(DOUBLY_DIR)/doubly.a

INC				=	../../include/
LIBFT_DIR		=	$(INC)libft/
LIBFT			=	$(LIBFT_DIR)libft.a

FILES			=	main \
					utils \
					test_create \
					test_delete \
					test_insert \
					test_read \
					test_utils

SRCS_DIR		=	./
SRCS			=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR		=	./
OBJS			=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

# Project file rule
$(NAME): $(OBJS)
	@make all -C $(LIBFT_DIR)
	@make all -C $(DOUBLY_DIR)
	@echo "\033[92mBuild test for doubly linked list...\033[0m"
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
	make -C $(DOUBLY_DIR) clean
	make -C $(LIBFT_DIR) clean

# Make fclean
fclean: 
	@echo "\033[92mForce clean test files...\033[0m"
	rm -rf $(OBJS)
	rm -rf $(NAME)
	make -C $(DOUBLY_DIR) fclean
	make -C $(LIBFT_DIR) fclean

# Make re
re: 
	make fclean
	make all

.PHONY: all fclean clean re
