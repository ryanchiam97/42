# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twtan <twtan@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/05 19:57:46 by twtan             #+#    #+#              #
#    Updated: 2025/06/05 20:08:59 by twtan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Parameters
OUTPUT = libftprintf.a
LIBFTDIR = ./libft
LIBFTA = libft.a
CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -Ilibft
HEADER = ft_printf.h
LIBHEADER = libft.h
SRCS =	ft_printf.c \
	ft_prtfuncs.c \
	ft_support.c \
	ft_parser.c \
	ft_flags.c \
	ft_format.c
	
# Commands
OBJS = ${SRCS:.c=.o}
RM = rm -fr

.PHONY: ${LIBFTDIR} all clean fclean re

%.o: %.c ${HEADER} 
		${CC} ${CFLAGS} -c $< -o $@

all: ${LIBFTDIR} ${OUTPUT}

${LIBFTDIR}:
	make -C ${LIBFTDIR}
	
${OUTPUT}: ${LIBFTDIR} ${OBJS} ${HEADER}
	cp ${LIBFTDIR}/${LIBFTA} ./${OUTPUT}
	@${AR} ${OUTPUT} ${OBJS}

clean:
	make -C ${LIBFTDIR} clean
	@${RM} ${OBJS}

fclean:	
	make -C ${LIBFTDIR} fclean
	@${RM} ${OUTPUT} ${OBJS}
		
re: fclean all
