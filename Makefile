# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 17:24:48 by bshintak          #+#    #+#              #
#    Updated: 2022/06/24 10:43:36 by bshintak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(VERBOSE).SILENT:

NAME		=	minitalk
CLIENT		=	client
SERVER		=	server

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -fsanitize=address
RM			=	rm -f
MKD			=	mkdir
INC			=	-I ./Libft -I ./Printf

LIBFT = ./Libft/libft.a
LIBFT_PATH = ./Libft

FT_PRINTF = ./Printf/libftprintf.a
FT_PRINTF_PATH = ./Printf

SRC_NAME	=	client.c	\
				server.c

SRC_PATH = .
OBJ_PATH = ./objects

OBJ	= 	$(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))
SRC	=	$(addprefix $(SRC_PATH)/, $(SRC_NAME))

all: $(NAME)

$(LIBFT): $(shell make -C $(LIBFT_PATH) -q libft.a)
	make -C $(LIBFT_PATH)

$(FT_PRINTF): $(shell make -C $(FT_PRINTF_PATH) -q libftprintf.a)
	make -C $(FT_PRINTF_PATH)

$(SERVER) : objects/server.o
	$(CC) $(CFLAGS) objects/server.o $(INC) $(LIBFT) $(FT_PRINTF) -o $(SERVER)
	echo "\x1b[36m[SERVER COMPILED]\x1b[0m"

$(CLIENT) : objects/client.o
	$(CC) $(CFLAGS) objects/client.o $(INC) $(LIBFT) $(FT_PRINTF) -o $(CLIENT)
	echo "\x1b[36m[CLIENT COMPILED]\x1b[0m"

$(NAME) : $(LIBFT) $(FT_PRINTF) $(CLIENT) $(SERVER)
		echo "\x1b[36m[MINITALK COMPILED]\x1b[0m"

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	$(MKD) -p objects
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(FT_PRINTF_PATH)
	make clean -C $(LIBFT_PATH)
	$(RM) -rf $(OBJ_PATH)
	echo "\033[33mRemoving object files...\033[0m"

fclean: clean
		make fclean -C $(LIBFT_PATH)
		make fclean -C $(FT_PRINTF_PATH)
		$(RM) $(NAME)
		$(RM) $(CLIENT)
		$(RM) $(SERVER)
		echo "\033[31mRemoving $(NAME)...\033[0m"

re: fclean all

.PHONY:	all clean fclean re force
