LIBFTDIR = libft
LIBFTLIB = libft.a
NAME = pushswap.a

SOURCES = pushswap.c\
input.c

OBJCTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFTLIB) :
	make -C $(LIBFTDIR) bonus

$(NAME): $(OBJECTS) $(LIBFTLIB)
	cp $(LIBFTDIR)/$(LIBFTLIB) $(NAME)
	ar rcs $(NAME) $(OBJCTS)

clean:
	make -C $(LIBFTDIR) fclean
	rm -f $(NAME)

fclean: clean
	make -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re