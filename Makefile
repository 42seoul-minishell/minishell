# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bolee <bolee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 14:29:10 by bolee             #+#    #+#              #
#    Updated: 2022/12/13 14:29:11 by bolee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project File
NAME			= minishell
LIB_NAME		= libminishell.a

# Project sources, includes, builds
CMD_DIR			= ./src/cmd/
UTILS_DIR		= ./src/utils/
ERROR_DIR		= ./src/error/
LIBFT_DIR		= ./src/libft/
DOUBLYDIR		= ./src/internal/doublylist/
HASHDIR			= ./src/internal/hashtable/
COREDIR			= ./src/internal/core/
GLOBALDIR		= ./src/internal/global/
PARSERDIR		= ./src/internal/parser/
TOKENIZERDIR	= ./src/internal/tokenizer/
SYNTAXDIR		= ./src/internal/syntax/
WILDCARDDIR		= ./src/internal/wildcard/
EXPANDDIR		= ./src/internal/expand/
BINTREEDIR		= ./src/internal/bintree/
EXECUTORDIR		= ./src/internal/executor/
BUILTINDIR		= ./src/internal/builtin/

# Library Directory
LIB_DIR			= ./lib

# Libaray Files
ERROR			= $(LIB_DIR)/liberror.a
UTILS			= $(LIB_DIR)/libutils.a
LIBFT			= $(LIB_DIR)/libft.a
HASH			= $(LIB_DIR)/libhashtable.a
DOUBLY			= $(LIB_DIR)/libdoubly.a
CORE			= $(LIB_DIR)/libcore.a
GLOBAL			= $(LIB_DIR)/libglobal.a
PARSER			= $(LIB_DIR)/libparser.a
TOKENIZER		= $(LIB_DIR)/libtokenizer.a
SYNTAX			= $(LIB_DIR)/libsyntax.a
WILDCARD		= $(LIB_DIR)/libwildcard.a
EXPAND			= $(LIB_DIR)/libexpand.a
BINTREE			= $(LIB_DIR)/libbintree.a
EXECUTOR		= $(LIB_DIR)/libexecutor.a
BUILTIN			= $(LIB_DIR)/libbuiltin.a

# Includ directory
INC				= ./include
LIB_DIR			= ./lib
FILES			= main

SRCS_DIR		= $(CMD_DIR)
SRCS			= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS			= $(SRCS:.c=.o)

# Compiler Flag and Command
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -I$(INC)
UNAME			= $(shell uname -s)

# Debugging Flag
DEBUG			= -g


# Main rule
all:
	@echo "\033[92mBuild minishell daemon...\033[0m"
	make $(NAME)

# Object rule
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Project file rule
ifeq ($(UNAME), Linux)
LINKING_FLAGS	= -I/usr/lib32 -lreadline
$(NAME): $(OBJS)
	@mkdir -p $(LIB_DIR)
	@make bonus -C $(LIBFT_DIR)
	@make all -C $(ERROR_DIR)
	@make all -C $(UTILS_DIR)
	@make all -C $(HASHDIR)
	@make all -C $(DOUBLYDIR)
	@make all -C $(COREDIR)
	@make all -C $(PARSERDIR)
	@make all -C $(GLOBALDIR)
	@make all -C $(TOKENIZERDIR)
	@make all -C $(SYNTAXDIR)
	@make all -C $(BINTREEDIR)
	@make all -C $(EXPANDDIR)
	@make all -C $(WILDCARDDIR)
	@make all -C $(EXECUTORDIR)
	@make all -C $(BUILTINDIR)
	@echo "\033[92mBuild minishell daemon...\033[0m"
	ar rcsuvT $(LIB_DIR)/$(LIB_NAME) $(ERROR) $(UTILS) $(LIBFT) $(HASH) $(DOUBLY) $(CORE) $(GLOBAL) $(PARSER) $(TOKENIZER) $(SYNTAX) $(WILDCARD) $(EXPAND) $(BINTREE) $(EXECUTOR) $(BUILTIN)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./lib -lminishell $(LINKING_FLAGS)
else
LINKING_FLAGS	= -I/Users/$(USER)/.brew/opt/readline/include -L/Users/$(USER)/.brew/opt/readline/lib -lreadline
$(NAME): $(OBJS)
	@mkdir -p $(LIB_DIR)
	@make bonus -C $(LIBFT_DIR)
	@make all -C $(ERROR_DIR)
	@make all -C $(UTILS_DIR)
	@make all -C $(HASHDIR)
	@make all -C $(DOUBLYDIR)
	@make all -C $(COREDIR)
	@make all -C $(PARSERDIR)
	@make all -C $(GLOBALDIR)
	@make all -C $(TOKENIZERDIR)
	@make all -C $(SYNTAXDIR)
	@make all -C $(BINTREEDIR)
	@make all -C $(EXPANDDIR)
	@make all -C $(WILDCARDDIR)
	@make all -C $(EXECUTORDIR)
	@make all -C $(BUILTINDIR)
	@echo "\033[92mBuild minishell daemon...\033[0m"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(ERROR) $(UTILS) $(LIBFT) $(HASH) $(DOUBLY) $(CORE) $(GLOBAL) $(PARSER) $(TOKENIZER) $(SYNTAX) $(WILDCARD) $(EXPAND) $(BINTREE) $(EXECUTOR) $(BUILTIN) $(LINKING_FLAGS)
endif

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
	make -C $(PARSERDIR) clean
	make -C $(GLOBALDIR) clean
	make -C $(TOKENIZERDIR) clean
	make -C $(SYNTAXDIR) clean
	make -C $(BINTREEDIR) clean
	make -C $(EXPANDDIR) clean
	make -C $(WILDCARDDIR) clean
	make -C $(EXECUTORDIR) clean
	make -C $(BUILTINDIR) clean



# Make fclean
fclean:
	@echo "\033[92mForce clean daemon files...\033[0m"
	rm -rf $(BUILDDIR)
	rm -rf $(OBJS)
	rm -rf $(NAME)
	rm -rf $(LIB_DIR)/*
	make -C $(ERROR_DIR) fclean
	make -C $(UTILS_DIR) fclean
	make -C $(HASHDIR) fclean
	make -C $(DOUBLYDIR) fclean
	make -C $(COREDIR) fclean
	make -C $(LIBFT_DIR) fclean
	make -C $(PARSERDIR) fclean
	make -C $(GLOBALDIR) fclean
	make -C $(TOKENIZERDIR) fclean
	make -C $(SYNTAXDIR) fclean
	make -C $(BINTREEDIR) fclean
	make -C $(EXPANDDIR) fclean
	make -C $(WILDCARDDIR) fclean
	make -C $(EXECUTORDIR) fclean
	make -C $(BUILTINDIR) fclean

# Make re
re:
	@echo "\033[92mRebuild daemon files...\033[0m"
	make fclean
	make all

.PHONY: all fclean clean re
