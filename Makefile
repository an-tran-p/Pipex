# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atran <atran@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 17:50:04 by atran             #+#    #+#              #
#    Updated: 2025/02/01 18:04:54 by atran            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = pipex.c pipex_utils.c check.c

OBJS = $(SRCS:%.c=%.o)

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

all : $(NAME)

$(OBJS): %.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJS)
		make all -C Libft
		make all -C Printf
		cc $(OBJS) -LLibft -lft -LPrintf -lftprintf -o $(NAME)

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
