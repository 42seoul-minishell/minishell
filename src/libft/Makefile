# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 16:45:57 by bolee             #+#    #+#              #
#    Updated: 2022/03/29 13:13:26 by bolee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAG		=	-Wall -Werror -Wextra -I$(INC)

INC			= ../../include
LIB_DIR		= ../../lib/

AR			=	ar
ARFLAG		=	rcusv

CFILES		=	ft_isalpha.c ft_isdigit.c ft_isalnum.c	\
			ft_isascii.c ft_isprint.c ft_strlen.c \
			ft_memset.c ft_bzero.c ft_memcpy.c \
			ft_memmove.c ft_strlcpy.c ft_strlcat.c \
			ft_calloc.c ft_strdup.c ft_toupper.c \
			ft_tolower.c ft_strchr.c ft_strrchr.c \
			ft_strncmp.c ft_memchr.c ft_memcmp.c \
			ft_strnstr.c ft_atoi.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c \
			ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_strcmp.c
BONUS		=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS		=	$(CFILES:.c=.o)
OBJS_B		=	$(BONUS:.c=.o)
INCLUDE		=	../../include
NAME		=	libft.a

ifeq ($(MAKECMDGOALS), bonus)
$(NAME): $(OBJS) $(OBJS_B)
	$(AR) $(ARFLAG) $@ $?
	mv $(NAME) $(LIB_DIR)
else
$(NAME): $(OBJS)
	$(AR) $(ARFLAG) $@ $?
	mv $(NAME) $(LIB_DIR)
endif

.PHONY: all
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAG) -c $? -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(OBJS_B)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

.PHONY: bonus
bonus: $(NAME)
