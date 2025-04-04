CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Object files
OBJ = main.o Fixed.o Point.o bsp.o

# Executable
TARGET = bsp

# Rule to build the executable
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Compile the source files
main.o: main.cpp Fixed.hpp Point.hpp bsp.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Fixed.o: Fixed.cpp Fixed.hpp
	$(CXX) $(CXXFLAGS) -c Fixed.cpp

Point.o: Point.cpp Point.hpp Fixed.hpp
	$(CXX) $(CXXFLAGS) -c Point.cpp

bsp.o: bsp.cpp bsp.hpp Point.hpp Fixed.hpp
	$(CXX) $(CXXFLAGS) -c bsp.cpp

# Clean the object files
clean:
	rm -f $(OBJ) $(TARGET)
