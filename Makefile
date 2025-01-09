# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atran <atran@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 17:50:04 by atran             #+#    #+#              #
#    Updated: 2025/01/06 18:28:53 by atran            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = pipex.c 

OBJS = $(SRCS:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

$(NAME) :
		make all -C libft
		make all -C Printf
		cc $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

clean : 
		$(RM) $(OBJS)
		make clean -C libft
		make clean -C Printf

fclean : clean
		$(RM) $(NAME)
		make fclean -C libft
		make fclean -C Printf

re : fclean all

.PHONY: all clean fclean re