# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Target
NAME = RPN

# Source files
SRCS = main.cpp RPN.cpp
OBJS = $(SRCS:.cpp=.o)

# Build the executable
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Clean object files
clean:
	rm -f $(OBJS)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all