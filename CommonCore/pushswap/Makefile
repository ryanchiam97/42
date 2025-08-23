LIBFTDIR = libft
LIBFTLIB = libft.a
NAME = pushswap

SOURCES = 	pushswap.c\
			i_parsehandler.c\
			i_parsehelper.c\
			i_initstack.c\
			p_sortthree.c\
			p_sortfourfive.c\
			p_radix.c\
			op_push.c\
			op_swap.c\
			op_rotate.c\
			op_revrotate.c

OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFTLIB) :
	make -C $(LIBFTDIR) bonus

$(NAME): $(OBJECTS) $(LIBFTLIB)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFTDIR)/$(LIBFTLIB) -o $(NAME)

clean:
	make -C $(LIBFTDIR) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re