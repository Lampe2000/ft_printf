# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmisbah <hmisbah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 14:12:36 by ysensoy           #+#    #+#              #
#    Updated: 2022/11/20 04:29:21 by hmisbah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT		= libft
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
AR			= ar rcs
SRC	= ft_printf.c ft_printf_utils.c 
OBJ = $(SRC:%.c=%.o)

%.o : %.c libft.h
	$(CC) $(FLAGS) -c $<

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)

clean:
	@rm -f *.o
	@make clean -C $(LIBFT)

fclean:	clean
	@$(RM) -f $(NAME)
	@$(RM) -f $(LIBFT)/libft.a

re:	fclean all
