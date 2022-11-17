# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 11:13:33 by mingkim           #+#    #+#              #
#    Updated: 2022/11/16 17:31:37 by mingkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project File
NAME			= minishell

# Project sources, includes, builds
CMD_DIR			= ./src/cmd/
UTILS_DIR		= ./src/utils/
ERROR_DIR		= ./src/error/
LIBFT_DIR		= ./include/libft/
DOUBLYDIR		= ./src/internal/doublylist/
HASHDIR			= ./src/internal/hashtable/
COREDIR			= ./src/internal/core/
TOKENIZERDIR	= ./src/internal/tokenizer/
LEXERDIR		= ./src/internal/lexer/
GLOBALDIR		= ./src/internal/global/

ERROR			= $(ERROR_DIR)error.a
UTILS			= $(UTILS_DIR)utils.a
LIBFT			= $(LIBFT_DIR)libft.a
HASH			= $(HASHDIR)hashtable.a
DOUBLY			= $(DOUBLYDIR)doubly.a
CORE			= $(COREDIR)core.a
TOKENIZER		= $(TOKENDIR)tokenizer.a
LEXER			= $(LEXERDIR)lexer.a
GLOBAL			= $(GLOBALDIR)global.a

BUILDDIR		= ./build/
INC				= ./include/minishell.h
FILES			= main

SRCS_DIR	= $(CMD_DIR)
SRCS		= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS		= $(SRCS:.c=.o)

# Compiler Flag and Command
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
LINKING_FLAGS	= -lreadline -L ${HOME}/.brew/opt/readline/lib
COMPILE_FLAGS	= -I${HOME}/.brew/opt/readline/include
# Debugging Flag
DEBUG			= -g


# Main rule
all:  $(BUILDDIR)
	@make all -C $(ERROR_DIR)
	@make all -C $(UTILS_DIR)
	@make all -C $(HASHDIR)
	@make all -C $(DOUBLYDIR)
	@make all -C $(COREDIR)
	@make all -C $(LIBFT_DIR)
	@make all -C $(TOKENIZERDIR)
	@make all -C $(LEXERDIR)
	@make all -C $(GLOBALDIR)
	@echo "\033[92mBuild minishell daemon...\033[0m"
	make $(NAME)

# Object dir rule
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Object rule
%.o: %.c
	$(CC) $(CFLAGS) $(COMPILE_FLAGS) -c $< -I$(INC)minishell.h -o $@

# Project file rule
$(NAME): $(OBJS)
	@make all -C $(ERROR_DIR)
	@make all -C $(UTILS_DIR)
	@make all -C $(HASHDIR)
	@make all -C $(DOUBLYDIR)
	@make all -C $(COREDIR)
	@make all -C $(LIBFT_DIR)
	@make all -C $(TOKENIZERDIR)
	@make all -C $(LEXERDIR)
	@make all -C $(GLOBALDIR)
	@echo "\033[92mBuild minishell daemon...\033[0m"
	$(CC) $(CFLAGS) $(LINKING_FLAGS) -o $(BUILDDIR)$(NAME) $(OBJS) $(ERROR) $(UTILS) $(DOUBLY) $(CORE) $(HASH) $(TOKENIZER) $(LIBFT) $(LEXER) $(GLOBAL) -I$(INC)

# Make clean
clean:
	@echo "\033[92mClean daemon files...\033[0m"
	rm -rf $(OBJS)
	make -C $(ERROR_DIR) clean
	make -C $(UTILS_DIR) clean
	make -C $(HASHDIR) clean
	make -C $(DOUBLYDIR) clean
	make -C $(COREDIR) clean
	make -C $(LIBFT_DIR) clean
	make -C $(TOKENIZERDIR) clean
	make -C $(LEXERDIR) clean
	make -C $(GLOBALDIR) clean

# Make fclean
fclean: 
	@echo "\033[92mForce clean daemon files...\033[0m"
	rm -rf $(BUILDDIR)
	rm -rf $(OBJS)
	rm -rf $(NAME)
	make -C $(ERROR_DIR) fclean
	make -C $(UTILS_DIR) fclean
	make -C $(HASHDIR) fclean
	make -C $(DOUBLYDIR) fclean
	make -C $(COREDIR) fclean
	make -C $(LIBFT_DIR) fclean
	make -C $(TOKENIZERDIR) fclean
	make -C $(LEXERDIR) fclean
	make -C $(GLOBALDIR) fclean

# Make re
re: 
	make fclean
	make all

.PHONY: all fclean clean re
