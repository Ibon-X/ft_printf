# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipresno- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 13:44:38 by ipresno-          #+#    #+#              #
#    Updated: 2022/10/03 12:25:40 by ipresno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_putchar.c ft_putstr.c ft_putnbr.c ft_putunbr.c ft_puthex.c ft_printf.c\

OBJS	= $(SRCS:.c=.o)

CC		= gcc -Wall -Werror -Wextra

LIBC	= ar rcs

RM 		= rm -rf

%.o: %.c 
		$(CC) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
			$(LIBC) $@ $^

clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
