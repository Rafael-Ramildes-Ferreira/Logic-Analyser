CC = g++

OUTPUT_FILE = a.out

SRC_DIR = src
OBJ_DIR = obj

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

FLAGS = -Wall -Wextra -pedantic -fsanitize=address 

$(OBJ_DIR):
	mkdir $@

all: $(OBJ_FILES)
	$(CC) $^ -o $(OUTPUT_FILE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(OBJ_DIR)
	$(CC) -c $< -o $@

run: all
	./$(OUTPUT_FILE)

clean:
	rm -rf *.out *.o
	rm -rf obj