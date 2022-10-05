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
MAIN_SRCS		=	main.c

MAIN_OBJS		=	$(MAIN_SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(COMFILE_FLAGS) -c $< -o $@

$(NAME) : $(MAIN_OBJS)
	$(CC) $(CFLAGS) $(LINKING_FLAGS) $(MAIN_OBJS) -o $(NAME)

.PHONY : all
all: $(NAME)

.PHONY : clean
clean:
	rm -rf $(MAIN_OBJS)

.PHONY : fclean
fclean:
	make clean
	rm -rf $(NAME)

.PHONY : re
re :
	make fclean
	make all
