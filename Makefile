SRC =	

UTILS = 

SOURCES = $(SRC) $(UTILS)
NAME = so_long
RM = rm -rf
CC = gcc
LIBFT_DIR = ./Libft
MLX_DIR = minilibx-linux
INCLUDE_P = -I include
CFLAGS = -Wall -Wextra -Werror $(INCLUDE_P) -fsanitize=address -g3
OBJ = $(SOURCES:.c=.o)
LIBFT = /libft.a
MLX_LIB = -L$(MLX_DIR) -lmlx
X11_LIB = -lXext -lX11 -lm
all: $(NAME)

$(NAME) : $(OBJ) 
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) $(OBJ) $(LIBFT_DIR)$(LIBFT) -o $(NAME) $(MLX_LIB)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJ)

fclean :  clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

