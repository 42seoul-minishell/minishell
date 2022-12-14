# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bolee <bolee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 14:18:20 by bolee             #+#    #+#              #
#    Updated: 2022/12/13 14:18:21 by bolee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project File
NAME			=	core.a

# Compiler Flag and Command
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
COMPILE_FLAGS	= -I/Users/$(USER)/.brew/opt/readline/include
AR				=	ar rcsuv

INC				=	../../../include

FILES			=	prompt \
					signal

SRCS_DIR		=	./
SRCS			=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR		=	./
OBJS			=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))



%.o: %.c
	$(CC) $(CFLAGS) $(COMPILE_FLAGS) -c $< -o $@

# Main rule
all: 
	@echo "\033[92mBuild core...\033[0m"
	@make $(NAME)

# Project file rule
$(NAME): $(OBJS)
	$(AR) $@ $?

# Make clean
clean:
	@echo "\033[92mClean core files...\033[0m"
	rm -rf $(OBJS)

# Make fclean
fclean:
	@echo "\033[92mForce clean core files...\033[0m"
	rm -rf $(OBJS)
	rm -rf $(NAME)

# Make re
re:
	make fclean
	make all

.PHONY: all fclean clean re
