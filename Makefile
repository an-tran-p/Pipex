# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atran <atran@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 17:50:04 by atran             #+#    #+#              #
#    Updated: 2025/01/29 20:53:07 by atran            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = pipex.c

OBJS = $(SRCS:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

$(NAME) :
		make all -C Libft
		make all -C Printf
		cc $(CFLAGS) $(SRCS) -LLibft -lft -LPrintf -lftprintf -o $(NAME)

all : $(NAME)

clean :
		$(RM) $(OBJS)
		make clean -C Libft
		make clean -C Printf

fclean : clean
		$(RM) $(NAME)
		make fclean -C Libft
		make fclean -C Printf

re : fclean all

.PHONY: all clean fclean re
