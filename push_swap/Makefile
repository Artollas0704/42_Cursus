# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 14:34:46 by aalves-p          #+#    #+#              #
#    Updated: 2022/12/29 09:52:23 by aalves-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CC = gcc
CFLAGS= -Wall -Wextra -Werror
LIBCREATE = ar rcs
RM = rm -f
OBJS = $(FILE_SRCS:.c=.o)
#BONUS_OBJ = $(BONUS:.c=.o)
FILE_SRCS = ft_split.c \
ft_strlen.c \
push_swap_check.c \
push_swap.c \
ft_atoi.c \
ft_lst_utils.c \

#BONUS = ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c \

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

#bonus: $(BONUS_OBJ)
#$(LIBCREATE) $(NAME) $(BONUS_OBJ)

.PHONY: all clean fclean re bonus