# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 16:33:31 by mingkim           #+#    #+#              #
#    Updated: 2022/10/31 16:59:23 by gimmingyu        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project File
NAME			=	hashtable.a

# Compiler Flag and Command
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar rcsuv

INC				=	hashtable.h

FILES			=	create \
					delete \
					hashtable \
					insert \
					search \
					utils \

SRCS_DIR		=	./
SRCS			=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR		=	./
OBJS			=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Main rule
all: 
	@echo "\033[92mBuild hashtable...\033[0m"
	@make $(NAME)

# Project file rule
$(NAME): $(OBJS)
	$(AR) $@ $?

# Make clean
clean:
	@echo "\033[92mClean hashtable files...\033[0m"
	rm -rf $(OBJS)

# Make fclean
fclean:
	@echo "\033[92mForce clean hashtable files...\033[0m"
	rm -rf $(OBJS)
	rm -rf $(NAME)

# Make re
re:
	make fclean
	make all

.PHONY: all fclean clean re
