NAME = Zombie

CPP = c++
CPP_FLAGS = -Werror -Wextra -Wall -std=c++98

SRC = main.cpp\
		newZombie.cpp\
		randomChump.cpp\
		Zombie.cpp\

OBJ = $(SRC:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJ)
	$(CPP) $(CPP_FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPP_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re