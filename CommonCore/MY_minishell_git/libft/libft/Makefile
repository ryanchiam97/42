# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twtan <twtan@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 14:43:25 by twtan             #+#    #+#              #
#    Updated: 2025/05/07 15:34:11 by twtan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Parameters
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
HEADER = libft.h
SRCS = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_substr.c \
	ft_strncmp.c \
	ft_strtrim.c \
	ft_split.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strnstr.c \
	ft_strmapi.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_atoi.c \
	ft_itoa.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

# Commands
OBJS = ${SRCS:.c=.o}
CC = cc 
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -fr

%.o: %.c $(HEADER)
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}:   ${OBJS}
		${AR} ${NAME} ${OBJS}

clean:
		@${RM} ${OBJS}
		@echo "libft clean." 

fclean: 
		@${RM} ${OBJS}
		@${RM} ${NAME}
		@echo "libft fclean."

re: fclean all

# Phony to recognise for make command line
.PHONY: all clean fclean re
