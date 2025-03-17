#Makefile 

#Compiler
CC = g++

#Compiler flags
CPP_FLAGS = -Wall -Iinc

#Source files
SOURCE = src/main.cpp src/socket.cpp src/user_interface.cpp

#Linker flags
LD_FLAGS = -lpthread

#Oject files
OBJ = $(SOURCE:.cpp=.o)

#Executable
TARGET = chatbox

# Link object files to create executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LD_FLAGS)

# Compile source files
%.o: %.cpp
	$(CC) -c $(CPP_FLAGS) $< -o $@

# Default target
all: $(TARGET)
	./$(TARGET)

# Clean object files
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets
.PHONY: all, clean