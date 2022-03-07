NAME =		utils.a

CC =		clang

CFLAGS = -c \
		-Wall\
		-Werror\
		-Wextra

AR		= ar
RM		= rm -rf

OBJ_DIR	= ./obj
SRC_DIR	= ./src

CFLAGS	= -g -Wall -Wextra -Werror
ARFLAGS	= rc


SRC	=	ft_bzero.c ft_calloc.c ft_split.c ft_memset.c
SRC	+=	ft_strdup.c ft_strjoin.c ft_strlen.c ft_strlcpy.c
SRC	+=	ft_strnstr.c ft_substr.c ft_free_ptr.c ft_strlcat.c

OBJ	= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(OBJ_DIR):
		mkdir -p ./obj

$(NAME): $(OBJ_DIR) $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test:
	echo $(OBJ)

.PHONY: all fclean clean re
