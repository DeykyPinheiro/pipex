# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 18:00:57 by demikael          #+#    #+#              #
#    Updated: 2022/03/06 21:39:06 by demikael         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

# PATH
UTILS_PATH = ./libraries/utils

CC		=	clang
CFLAGS	= -Wall -Werror -Wextra -g

RM		=	rm -rf

OBJ_DIR = ./obj
SRC_DIR = ./src

SRC	=	pipex.c default_functions.c parse_functions.c comands_flow.c
SRC +=	handle.c set_comands.c

OBJ	=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all:		$(NAME)

$(OBJ_DIR):
	mkdir -p ./obj

$(NAME):	$(OBJ_DIR) $(OBJ)
			$(MAKE) -C $(UTILS_PATH)
			$(CC) $(CFLAGS) $(OBJ) $(UTILS_PATH)/utils.a -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@


clean:
			$(RM) $(OBJ_DIR)
			$(MAKE) -C $(UTILS_PATH) clean

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) -C $(UTILS_PATH) fclean

re:			fclean all

r:	all
	clear
	./$(NAME) input_file.txt "tr a b" "tr b c" output_file.txt
	cat output_file.txt


v:	all
	clear
	valgrind --leak-check=full --track-origins=yes ./pipex input_file.txt "tr a b" "tr b c"  output_file.txt

t:	all
	clear
	$(MAKE) -C ./pipex-tester

n:
	clear
	norminette ./src ./libraries

test:
	@echo $(OBJ)

.PHONY: all clean fclean re r n
