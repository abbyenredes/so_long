GREEN = \033[0;32m
RED = \033[0;31m

SRC =	src/main.c \

UTILS = 

SRCS = $(SRC) $(UTILS)
NAME = so_long
CC = gcc
INCLUDE_P = -I include
CFLAGS = -Wall -Wextra -Werror $(INCLUDE_P) -fsanitize=address -g3
OBJ = $(SRCS:.c=.o)
INCLUDES = -L./mlx -lmlx -lXext -lX11 -lm
RM = rm -rf
all: $(NAME)

$(NAME) : $(OBJ) 
	@make -s -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INCLUDES) -L libft -lft
	@echo "$(GREEN)It has been compiled!!.👍$(NC)";

clean:
	@make clean -C libft
	rm -rf $(OBJ)

fclean :  clean
	@make fclean -s -C libft
	@rm -rf $(OBJ)
	@rm -rf $(NAME)
	@echo "$(RED)Full Cleaning...$(NC)"
	@echo "$(RED)Full Cleaned!$(NC)"

re: fclean all

.PHONY: all clean fclean re

