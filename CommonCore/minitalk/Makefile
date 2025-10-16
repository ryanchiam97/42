NAME_SERVER = server
NAME_CLIENT = client

SOURCES = 	server.c\
			client.c\

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wextra -Wall -Werror
MAKE = MAKE

FTPRINTF_DIR = ./ft_printf
FTPRINTF_LIB = ftprintf.a
FTPRINTF_FLAGS = -lftprintf

all : $(NAME_SERVER) $(NAME_CLIENT)

$(NAME): $(OBJECTS) $(FTPRINTF_DIR) / $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJECTS) -o$(NAME) -L$(FT_PRINTF_DIR) $(FTPRINTF_FLAGS)

%.o: %.c
	$(CC) $(CLAGS) -I$(FT_PRINT_DIR) -c $< -o $@

$(FTPRINTF_DIR)/$(FTPRINTF_LIB):
	@$(MAKE) -C $(FTPRINTF_DIR)

clean: 
	@$(MAKE) -C $(FTPRINTF_DIR) clean
	rm -f $(OBJECTS)

fclean: clean
	@$(MAKE) -C $(FTPRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re