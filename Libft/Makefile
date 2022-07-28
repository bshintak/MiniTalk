# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 14:57:28 by bshintak          #+#    #+#              #
#    Updated: 2022/06/24 10:48:31 by bshintak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a
SRC =	ft_atoi_libft

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I.

all:$(NAME)

$(NAME): $(SRC:=.o)
			ar rc $(NAME) $(SRC:=.o)
clean:
	$(RM)	$(SRC:=.o) $(BONUS:=.o)
fclean: clean
		$(RM)	$(NAME)
re:	fclean	$(NAME)

.PHONY: all clean fclean re
