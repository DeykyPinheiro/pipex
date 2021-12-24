# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 18:00:57 by demikael          #+#    #+#              #
#    Updated: 2021/12/24 17:55:06 by demikael         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

# PATH
LIBFT_PATH = ./libraries/libft

CC		=	clang
CFLAGS	= -Wall -Werror -Wextra

AR		=	ar
ARFLAGS	=	rcs


RM		=	rm -rf

OBJ_DIR = ./obj
SRC_DIR = ./src

SRC	=	pipex.c

OBJ	=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all:		$(NAME)
			@echo "entrei aqui"
			$(CC) $(CFLAGS) $(NAME) $(OBJ) -o $(NAME)


$(NAME):	$(OBJ)
			$(MAKE) -C $(LIBFT_PATH)
			cp $(LIBFT_PATH)/libft.a $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@


clean:
			$(RM) $(OBJ_DIR)/*
			$(MAKE) -C $(LIBFT_PATH) clean

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) -C $(LIBFT_PATH) fclean

re:			fclean all

r:
	clear && ./$(NAME) input_file.txt cat "tr a b" "tr b a" "grep 'line f'" output_file.txt
# cat input_file.txt | tr a c | tr b c | tr d c | grep 'line e'
# ./a.out input_file.txt "tr a b" "grep 'line b'" output_file.txt
# same cat input_file.txt | tr a b | grep 'line b'

t:
			@echo "entrei aqui"


test:
	@echo $(OBJ)

.PHONY: all clean fclean re r
