# Project File
NAME			=	parser.a

# Compiler Flag and Command
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar rcsuv

INC				=	../../../include/minishell.h

FILES			=	parser

SRCS_DIR		=	./
SRCS			=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR		=	./
OBJS			=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

EXPANDDIR		=	./expand/
TOKENIZERDIR	=	./tokenizer/
SYNTAXDIR		=	./syntax/
# WILDCARD		=	./wildcard

EXPAND			= $(EXPANDDIR)expand.a
TOKENIZER		= $(TOKENIZERDIR)tokenizer.a
SYNTAX			= $(SYNTAXDIR)syntax.a
# WILDCARD		= $(WILDCARDDIR)wildcard.a

# Main rule
all: 
	@make all -C $(EXPANDDIR)
	@make all -C $(SYNTAXDIR)
	@make all -C $(TOKENIZERDIR)
	@echo "\033[92mBuild parser...\033[0m"
	@make $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -I$(INC)minishell.h -o $@

# Project file rule
$(NAME): $(OBJS)
	$(AR) $@ $?
	@libtool -static $(EXPAND) $(TOKENIZER) $(SYNTAX) $(NAME) -o $(NAME)


# Make clean
clean:
	@echo "\033[92mClean parser files...\033[0m"
	@make -C $(EXPANDDIR) clean
	@make -C $(TOKENIZEDIR) clean
	@make -C $(SYNTAX) clean
	rm -rf $(OBJS)

# Make fclean
fclean:
	@echo "\033[92mForce clean parser files...\033[0m"
	@make -C $(EXPANDDIR) fclean
	@make -C $(TOKENIZERDIR) fclean
	@make -C $(SYNTAXDIR) fclean
	rm -rf $(OBJS)
	rm -rf $(NAME)

# Make re
re:
	make fclean
	make all

.PHONY: all fclean clean re