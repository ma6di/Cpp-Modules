# Makefile for PmergeMe

# Executable name
NAME        := PmergeMe

# Compiler
CXX         := c++
COMMON_FLAGS:= -Wall -Wextra -Werror -std=c++98

# Build mode: use 'make MODE=debug' or 'make MODE=release'
MODE ?= release

ifeq ($(MODE),debug)
	CXXFLAGS := $(COMMON_FLAGS) -g -DDEBUG
else ifeq ($(MODE),release)
	CXXFLAGS := $(COMMON_FLAGS)
else
	$(error Unknown MODE '$(MODE)'. Use 'make MODE=debug' or 'make MODE=release')
endif

# Source and object files
SRC := main.cpp PmergeMe.cpp
OBJ := $(SRC:.cpp=.o)

# Default target
all: $(NAME)

# Link target
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile rule
%.o: %.cpp PmergeMe.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Cleanup rules
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
