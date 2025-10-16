NAME = fixed

CC = c++
FLAGS = -Wall - Wextra -Werror -std=c++20
HEADER_FILES = Fixed.hpp
HEADER_PATH = include/
OBJ_PATH = obj
SRC_PATH = source
OBJ = $(SRC:%.cpp=$(OBJ_PATH)/%.o)

RED = \e[1;31m
WHITE = \e[0m
BLUE = \e[34m
GREEN = \e[32m
YELLOW = \e[33m

all: $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp $(HEADERS) | $(OBJ_PATH)
	@(CC) $(FLAGS) - c $< -o $@

$(NAME)