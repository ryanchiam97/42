NAME = fractol

#sources
SOURCES = 	main.c\
			fractol.c\
			window.c\
			render.c\
			panzoom.c

#objects
OBJECTS = $(SOURCES:.c=.o)

#misc
CC = cc
CFLAGS = -g -Wextra -Werror -Wall
MAKE = make

#Libft
LIBFT_DIR = ./libft
LIBFT_LIB = libft.a
LIBFT_FLAGS = -lft

#Mlx Lib
MLX_DIR = ./mlx_linux
MLX_LIB = libmlx.a
MLX_FLAGS = -lmlx -lm -lz -lXext -lX11

#rules
all : $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_DIR)/$(LIBFT_LIB) $(MLX_DIR)/$(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) -L$(MLX_DIR) -L$(LIBFT_DIR) $(MLX_FLAGS) $(LIBFT_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

$(LIBFT_DIR)/$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR) bonus

$(MLX_DIR)/$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

clean: 
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJECTS)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
