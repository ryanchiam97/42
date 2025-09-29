NAME = fractol

#sources
SOURCES = 	main.c\
			fractol.c

#objects
OBJECTS = $(SOURCES:.c=.o)

#misc
CC = cc
CFLAGS = -Wextra -Werror -Wall
MAKE = make

#Libft
LIBFT_DIR = ./libft
LIBFT_LIB = libft.a
LIBFT_FLAGS = -lft -L$(LIBFT_DIR) -I$(LIBFT_DIR)
$(LIBFT_DIR)/$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR) bonus

#Mlx Lib
MLX_DIR = ./mlx_linux
MLX_LIB = libmlx.a
MLX_FLAGS = -lmlx -lm -lz -lXext -lX11 -L$(MLX_DIR) -I$(MLX_DIR)
$(MLX_DIR)/$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

#rules
all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS) $(LIBFT_DIR)/$(LIBFT_LIB) $(MLX_DIR)/$(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJECTS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

clean: 
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJECTS)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
