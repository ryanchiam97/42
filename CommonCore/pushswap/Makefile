LIBFTDIR = libft
LIBFTLIB = libft.a
NAME = pushswap.a

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

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFTLIB) :
	make -C $(LIBFTDIR) bonus

$(NAME): $(OBJECTS) $(LIBFTLIB)
	cp $(LIBFTDIR)/$(LIBFTLIB) $(NAME)
	ar rcs $(NAME) $(OBJECTS)

clean:
	make -C $(LIBFTDIR) fclean
	rm -f $(NAME)

fclean: clean
	make -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re