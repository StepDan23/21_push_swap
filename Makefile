# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 18:33:13 by mmcclure          #+#    #+#              #
#    Updated: 2019/03/05 14:17:59 by mmcclure         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker

NAME2 = push_swap

LIB = libft/libft.a

SRCS_BOTH = ./srcs/pusw_instr.c ./srcs/pusw_lst_min_max.c ./srcs/pusw_lstoper.c \
			./srcs/pusw_pivot.c ./srcs/pusw_readarg.c ./srcs/pusw_solve.c \
			./srcs/pusw_sort_quick.c \
			./libft/libft.a

SRCS_CHECK = ./srcs/checker.c

SRCS_PUSW = ./srcs/push_swap.c

all: $(NAME1) $(NAME2)

$(NAME1): $(LIB)
	gcc -Wall -Wextra -Werror $(SRCS_CHECK) $(SRCS_BOTH) -o $(NAME1)

$(NAME2): $(LIB)
	gcc -Wall -Wextra -Werror $(SRCS_PUSW) $(SRCS_BOTH) -o $(NAME2)

$(LIB):
	make -C libft/

clean:
	make -C libft/ clean

fclean: clean
	rm -f $(NAME1) $(NAME2)
	make -C libft/ fclean

re: fclean all
