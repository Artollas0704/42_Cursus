# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 21:31:15 by aralves-          #+#    #+#              #
#    Updated: 2024/04/28 16:23:51 by aralves-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBCREATE = ar rc
RM = rm -f
LIBFT_DIR = libft

OBJS = $(SRCS:.c=.o)
SRCS = ft_printf.c ft_printf_utils.c \

BONUS_OBJ = $(BONUS_SRCS:.c=.o)
BONUS_SRCS = ft_printf_utils_bonus.c ft_printf_utils_bonus2.c ft_printflags_unsigned_hexa_bonus.c\

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	
$(NAME): $(OBJS)
		make -C $(LIBFT_DIR)
		cp libft/libft.a .
		mv libft.a $(NAME)
	$(LIBCREATE) $(NAME) $(OBJS)

all: $(NAME) bonus

bonus: $(NAME) $(BONUS_OBJ)
	$(LIBCREATE) $(NAME) $(BONUS_OBJ)

clean:
	$(RM) $(OBJS) $(BONUS_OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) 
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re