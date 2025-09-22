LIBFTDIR = libft
LIBFTLIB = libft.a
NAME = push_swap

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
			op_revrotate.c\
			p_utils.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

MAKE = make

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS) $(LIBFTLIB)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFTDIR)/$(LIBFTLIB) -o $(NAME)

$(LIBFTLIB):
	$(MAKE) -C $(LIBFTDIR) bonus

clean:
	make -C $(LIBFTDIR) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re