# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/30 16:00:10 by twtan             #+#    #+#              #
#    Updated: 2025/11/05 21:36:06 by rchiam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# This make file is for project Minishell

# readline is not a standard package
# to install readline : sudo apt install libreadline-dev

NAME = minishell
BNAME = minishell_bonus

CC = cc
VAL = valgrind --leak-check=full --show-leak-kinds=all -s
CFLAGS = -Wall -Wextra -Werror -g 
LINKERS = -lreadline -lhistory -lcurses

# Library file
LIBFTLIB = libft/libftprintf.a

# include header files
LHEADER = ./libft/ft_printf.h
HEADER = minishell.h \
	ft_split_r/ft_split_r.h \
	ft_option_parser/ft_option_parser.h

# Source files - Mandatory
SRCS = minishell.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	ft_readline/ft_readline.c \
	ft_split_r/ft_split_r.c \
	ft_option_parser/ft_option_parser.c \
	minishell_signal_handler.c \
	minishell_builtin_echo.c \
	minishell_builtin_exit.c \
	minishell_builtin_pwd.c	\
	minishell_cmdline_handler.c

# Source files - Bonus
BSRCS = minishell_bonus.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	ft_readline/ft_readline.c \
	ft_split_r/ft_split_r.c \
	ft_option_parser/ft_option_parser.c \
	minishell_signal_handler.c \
	minishell_builtin_echo.c \
	minishell_builtin_exit.c \
	minishell_builtin_pwd.c \
	minishell_cmdline_handler.c

RM = rm -fr

# Object files
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

%.o: %.c $(LHEADER) $(HEADER)
	${CC} ${CFLAGS} -c $< -o $@

.PHONY: all re bonus fclean clean test testb

all: ${NAME}

bonus: ${BNAME}
	@cp ${BNAME} ${NAME}

${NAME}: ${LIBFTLIB} ${HEADER} ${LHEADER} ${OBJS}
	${CC} ${LINKERS} ${CFLAGS} ${OBJS} ${LIBFTLIB} -o ${NAME}
	
${BNAME}: ${LIBFTLIB} ${HEADER} ${LHEADER} ${BOBJS}
	${CC} ${LINKERS} ${CFLAGS} ${BOBJS} ${LIBFTLIB} -o ${BNAME}

${LIBFTLIB}:
	make -C libft

test: fclean ${NAME}
	clear
	${VAL} ./${NAME}

testb: fclean ${BNAME}
	clear
	${VAL} ./${BNAME}

re: fclean all

clean:
	${RM} ${OBJS}
	${RM} ${BOBJS}
	make -C libft clean
	@echo "\nClean done\n"

fclean: 
	${RM} ${OBJS} ${BOBJS}
	${RM} ${NAME} ${BNAME}
	make -C libft fclean
	@echo "\nFull clean done\n"
