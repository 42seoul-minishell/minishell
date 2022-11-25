# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 11:13:33 by mingkim           #+#    #+#              #
#    Updated: 2022/11/19 13:10:25 by gimmingyu        ###   ########.fr        #
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
GLOBALDIR		= ./src/internal/global/
PARSERDIR		= ./src/internal/parser/
TOKENIZERDIR	= ./src/internal/tokenizer/
SYNTAXDIR		= ./src/internal/syntax/
WILDCARDDIR		= ./src/internal/wildcard/
EXPANDDIR		= ./src/internal/expand/
BINTREEDIR		= ./src/internal/bintree/
EXECUTORDIR		= ./src/internal/executor/

# Libaray Files
ERROR			= $(ERROR_DIR)error.a
UTILS			= $(UTILS_DIR)utils.a
LIBFT			= $(LIBFT_DIR)libft.a
HASH			= $(HASHDIR)hashtable.a
DOUBLY			= $(DOUBLYDIR)doubly.a
CORE			= $(COREDIR)core.a
GLOBAL			= $(GLOBALDIR)global.a
PARSER			= $(PARSERDIR)parser.a
TOKENIZER		= $(TOKENIZERDIR)tokenizer.a
SYNTAX			= $(SYNTAXDIR)syntax.a
WILDCARD		= $(WILDCARDDIR)wildcard.a
EXPAND			= $(EXPANDDIR)expand.a
BINTREE			= $(BINTREEDIR)bintree.a
EXECUTOR		= $(EXECUTORDIR)executor.a

# Includ directory
INC				= ./include/
FILES			= main

SRCS_DIR		= $(CMD_DIR)
SRCS			= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS			= $(SRCS:.c=.o)

# Compiler Flag and Command
CC				= cc
CFLAGS			= -Wall -Wextra -Werror 
LINKING_FLAGS	= -l readline -L/opt/homebrew/opt/readline/lib
COMPILE_FLAGS	= -I/opt/homebrew/opt/readline/include

DEV_LINKING_FLAGS	= -L/opt/homebrew/opt/readline/lib
DEV_COMPILE_FLAGS	= -I/opt/homebrew/opt/readline/include

CPPFLAGS = -I/Users/bolee/.brew/opt/readline/include
LDFLAGS = -L/Users/bolee/.brew/opt/readline/lib -lreadline

# Debugging Flag
DEBUG			= -g


# Main rule
all:	
	@echo "\033[92mBuild minishell daemon...\033[0m"
	make $(NAME)

# Object rule
%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -I $(INC) -c $< -o $@

# Project file rule
$(NAME): $(OBJS)
	@make all -C $(ERROR_DIR)
	@make all -C $(UTILS_DIR)
	@make all -C $(HASHDIR)
	@make all -C $(DOUBLYDIR)
	@make all -C $(COREDIR)
	@make all -C $(LIBFT_DIR)
	@make all -C $(PARSERDIR)
	@make all -C $(GLOBALDIR)
	@make all -C $(TOKENIZERDIR)
	@make all -C $(SYNTAXDIR)
	@make all -C $(BINTREEDIR)
	@make all -C $(EXPANDDIR)
	@make all -C $(EXECUTORDIR)
	@make all -C $(WILDCARDDIR)
	@echo "\033[92mBuild minishell daemon...\033[0m"
	$(CC) $(CFLAGS) $(LDFLAGS) -I$(INC)minishell.h $(LIBFT) $(ERROR) $(UTILS) $(DOUBLY) $(PARSER) $(CORE) $(HASH) $(GLOBAL) $(TOKENIZER) $(SYNTAX) $(BINTREE) $(EXPAND) $(EXECUTOR) $(WILDCARD) -o $(NAME) $(OBJS) 
	
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
	make -C $(EXECUTORDIR) clean
	make -c $(WILDCARDDIR) clean
	
	

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
	make -C $(PARSERDIR) fclean
	make -C $(GLOBALDIR) fclean
	make -C $(TOKENIZERDIR) fclean
	make -C $(SYNTAXDIR) fclean
	make -C $(BINTREEDIR) fclean
	make -C $(EXPANDDIR) fclean
	make -C $(EXECUTORDIR) fclean
	make -C $(WILDCARDDIR) fclean
	

# Make re
re: 
	@echo "\033[92mRebuild daemon files...\033[0m"
	make fclean
	make all

.PHONY: all fclean clean re
