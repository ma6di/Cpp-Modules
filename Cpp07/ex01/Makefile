
C++ = c++
C++_FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

NAME = Iter

all: $(NAME)

$(NAME) : $(OBJ)
	$(C++) $(C++_FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(C++) $(C++_FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:
	fclean all

.PHONY: all clean fclean re

