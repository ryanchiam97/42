NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj
MLX_DIR = ./mlx_linux

SRCS = $(SRC_DIR)/main.c
OBJ = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

MLXFLAGS = -L$(MLX_DIR) -lmlx - L/usr/lib/X11 -lXext -lX11 -lmlx
INCLUDES = -I$(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
