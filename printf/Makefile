# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 14:45:58 by aalves-p          #+#    #+#              #
#    Updated: 2022/11/18 00:36:02 by aalves-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS= -Wall -Wextra -Werror
LIBCREATE = ar rc
RM = rm -f
OBJS = $(FILE_SRCS:.c=.o)
FILE_SRCS = ft_printf.c \
ft_putstr.c \
ft_putchar.c \
ft_printnb.c \
ft_puthexa.c \
ft_putunsigned.c \
ft_itoa.c \
ft_putpointer.c \

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) 
	
$(NAME) : $(OBJS)
	$(LIBCREATE) $(NAME) $(OBJS)

all: $(NAME)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re