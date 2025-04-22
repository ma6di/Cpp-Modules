# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 14:10:04 by mcheragh          #+#    #+#              #
#    Updated: 2025/04/22 14:10:06 by mcheragh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++ = c++
C++_FLAGS = -Wall -Werror -Wextra -std=c++98
SRC = main.cpp Span.cpp

OBJ = $(SRC:.cpp=.o)
NAME = Span

all: $(NAME)

$(NAME) : $(OBJ)
	$(C++) $(C++_FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(C++) $(C++_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
