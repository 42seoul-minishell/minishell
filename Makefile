# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 11:13:33 by mingkim           #+#    #+#              #
#    Updated: 2022/10/05 16:53:57 by mingkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project File
NAME			= minishell

# Project sources, includes, builds
CMD_DIR			= ./src/cmd/
UTILS_DIR		= ./src/utils/
INTERNAL_DIR	= ./src/internal/

UTILS			= ./src/utils/utils.a
INTERNAL		= ./src/internal/internal.a

BUILDDIR		= ./build/
INC				= ./include/
FILES			= $(shell ls $(CMD_DIR) | grep -E ".+\.c")
BUILD_OBJS		= $(addprefix $(CMD_DIR), $(FILES:.c=.o))

# Compiler Flag and Command
CC				= cc
CFLAGS			= -Wall -Wextra -Werror

# Debugging Flag
DEBUG			= -g


# Main rule
all: $(BUILDDIR)
	@make all -C $(UTILS_DIR)
	@make all -C $(INTERNAL_DIR)
	@echo "\033[92mBuild minishell daemon...\033[0m"
	make $(NAME)

# Object dir rule
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Object rule
%.o: %.c
	$(CC) $(CFLAGS) -I$(INC) -I$(UTILS) -I$(INTERNAL) -o $@ -c $<

# Project file rule
$(NAME): $(BUILD_OBJS)
	$(CC) $(CFLAGS) -o $(BUILDDIR)$(NAME) $(BUILD_OBJS) $(UTILS) $(INTERNAL)

# Utils rule
$(UTILS): 
	make all -C $(UTILS_DIR)/

# Internal rule
$(INTERNAL):
	make all -C $(INTERNAL_DIR)/

# Make clean
clean:
	@echo "\033[92mClean daemon files...\033[0m"
	rm -rf $(BUILDDIR)
	rm -rf $(BUILD_OBJS)
	make -C $(UTILS_DIR) clean
	make -C $(INTERNAL_DIR) clean

# Make fclean
fclean: 
	@echo "\033[92mForce clean daemon files...\033[0m"
	rm -rf $(BUILDDIR)
	rm -rf $(BUILD_OBJS)
	rm -rf $(NAME)
	make -C $(UTILS_DIR) fclean
	make -C $(INTERNAL_DIR) fclean

# Make re
re: 
	make fclean
	make all

.PHONY: all fclean clean re
