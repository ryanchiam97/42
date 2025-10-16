LIBFTDIR = libft
LIBFTLIB = libft.a
NAME = libftprintf.a

SOURCES = 	ft_printf.c \
			myputstr.c \
			printhex.c \
			printnbr.c \
			uprintnbr.c \
			printptr.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
MAKE = make

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFTLIB) :
	$(MAKE) -C $(LIBFTDIR) bonus

$(NAME) : $(OBJECTS) $(LIBFTLIB)
	cp $(LIBFTDIR)/$(LIBFTLIB) $(NAME)
	ar rcs $(NAME) $(OBJECTS)

clean : 
	$(MAKE) -C $(LIBFTDIR) clean
	rm -f $(OBJECTS)

fclean : clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re