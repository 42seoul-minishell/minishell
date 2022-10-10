# Project File
NAME			=	testBtree

# Compiler Flag and Command
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror

# Debugging Flag
DEBUG			=	-g

# Project sources, includes, builds
BTREE_DIR		=	../../src/internal/btree
BTREE			=	$(BTREE_DIR)/btree.a

INC				=	../../include/
LIBFT_DIR		=	$(INC)libft/
LIBFT			=	$(LIBFT_DIR)libft.a

FILES			=	main \
					utils \
					test_create \
					test_delete \
					test_insert \
					test_read 

SRCS_DIR		=	./
SRCS			=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR		=	./
OBJS			=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

# Project file rule
$(NAME): $(OBJS)
	@make all -C $(LIBFT_DIR)
	@make all -C $(BTREE_DIR)
	@echo "\033[92mBuild test for doubly linked list...\033[0m"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(BTREE) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC) -I$(BTREE) -I$(LIBFT) -c $< -o $@

# Main rule
all:
	make $(NAME)

# Make clean
clean:
	@echo "\033[92mClean test files...\033[0m"
	rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(BTREE_DIR) clean

# Make fclean
fclean: 
	@echo "\033[92mForce clean test files...\033[0m"
	rm -rf $(OBJS)
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(BTREE_DIR) fclean

# Make re
re: 
	make fclean
	make all

.PHONY: all fclean clean re
