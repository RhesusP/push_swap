# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 14:58:16 by cbernot           #+#    #+#              #
#    Updated: 2023/01/02 11:22:06 by cbernot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = ./main.c ./srcs/error.c ./srcs/radix_sort.c ./srcs/sort.c ./srcs/stack_op.c ./srcs/stack_op2.c ./srcs/stack_utils.c ./srcs/stack_utils2.c
OBJS = ${SRCS:.c=.o}

INCLUDE = ./includes/push_swap.c
FLAGS = -Wall -Werror -Wextra

%.o: %.c ${INCLUDE}
	cc ${FLAGS} -I ${INCLUDE} -c $< -o $@

${NAME}: ${OBJS}
	make -C ./libft
	cc ${OBJS} -L ./libft -l ft -o ${NAME}

all: ${NAME}

clean:
	make clean -C ./libft
	rm -f ${OBJS}

fclean: clean
	make fclean -C ./libft
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re