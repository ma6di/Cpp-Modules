NAME = PmergeMe
C++ = c++
C++_FLAGS = -Wall -Werror -Wextra -Wshadow -std=c++98

#Colors
RESET = \033[0;39m
GREEN = \033[0;92m

SRC = main.cpp PairKeeper.cpp
HEADER = MyList.hpp PairKeeper.hpp PmergeMe.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o : %.cpp $(HEADER)
	$(C++) $(C++_FLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
	$(C++) $(C++_FLAGS) $(OBJ) -g -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created!$(RESET)"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re