NAME=PhoneBook

CPP=c++
CPPFLAGS= -Werror -Wextra -Wall -std=c++98

SRC=Contact.cpp\
	main.cpp\
	PhoneBook.cpp

OBJ=$(SRC:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re:fclean all

.PHONY: all clean fclean re