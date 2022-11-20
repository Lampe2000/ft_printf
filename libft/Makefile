# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmisbah <hmisbah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 04:52:02 by hmisbah           #+#    #+#              #
#    Updated: 2022/11/20 04:52:03 by hmisbah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= cc

SRCS = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c \

SRCSB = \
	ft_lstnew.c ft_lstlast.c ft_lstsize.c \

OBJS		= $(SRCS:%.c=%.o)

BNS_OBJS	= $(SRCSB:%.c=%.o)

FLAGS		= -Wall -Werror -Wextra

%.o : %.c libft.h
	@$(CC) $(FLAGS) -c $<

all: $(NAME)

$(NAME):$(OBJS)
	@ar rc $(NAME) $(OBJS)

bonus: $(BNS_OBJS)
	@ar rc $(NAME) $(BNS_OBJS)

clean:
	rm -f $(OBJS) $(BNS_OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all
