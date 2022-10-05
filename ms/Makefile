# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bolee <bolee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 00:22:02 by bolee             #+#    #+#              #
#    Updated: 2022/09/22 00:22:03 by bolee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell
CC				=	gcc
CFLAGS			=	-Werror -Wall -Wextra 
LINKING_FLAGS	=	-lreadline -L${HOME}/.brew/opt/readline/lib
COMFILE_FLAGS	=	-I${HOME}/.brew/opt/readline/include
SRCS			=	main.c \
					Lexer.c \
					Parser.c \
					Syntax.c \
					Token.c \
					Tree.c \
					Utils/ft_split.c \
					Utils/ft_strchr.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(COMFILE_FLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(LINKING_FLAGS) $(OBJS) -o $(NAME)

.PHONY : all
all: $(NAME)

.PHONY : clean
clean:
	rm -rf $(OBJS)

.PHONY : fclean
fclean:
	make clean
	rm -rf $(NAME)

.PHONY : re
re :
	make fclean
	make all
