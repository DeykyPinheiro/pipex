# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 18:00:57 by demikael          #+#    #+#              #
#    Updated: 2022/01/17 01:35:32 by demikael         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

# PATH
LIBFT_PATH = ./libraries/libft

CC		=	clang
CFLAGS	= -Wall -Werror -Wextra

RM		=	rm -rf

OBJ_DIR = ./obj
SRC_DIR = ./src

SRC	=	pipex.c default_functions.c parse_functions.c comands_flow.c
SRC += validations.c handle.c set_comands.c

OBJ	=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all:		$(NAME)

$(OBJ_DIR):
	mkdir -p ./obj

$(NAME):	$(OBJ_DIR) $(OBJ)
			$(MAKE) -C $(LIBFT_PATH)
			$(CC) $(CFLAGS) $(OBJ) $(LIBFT_PATH)/libft.a -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@


clean:
			$(RM) $(OBJ_DIR)
			$(MAKE) -C $(LIBFT_PATH) clean

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) -C $(LIBFT_PATH) fclean

re:			fclean all

r:	all
	clear
	./$(NAME) input_file.txt "tr a b" "tr b c" output_file.txt
# cat input_file.txt | tr a c | tr b c | tr d c | grep 'line e'
# ./a.out input_file.txt "tr a b" "grep 'line b'" output_file.txt
# same cat input_file.txt | tr a b | grep 'line b'

v:
	valgrind ./$(NAME)
t:
	$(MAKE) -C ./pipex-tester


test:
	@echo $(OBJ)

.PHONY: all clean fclean re r
