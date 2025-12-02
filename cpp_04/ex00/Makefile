NAME = poly

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++20

SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
HEADERS = $(INC_PATH)/Animal.hpp $(INC_PATH)/Dog.hpp $(INC_PATH)/Cat.hpp $(INC_PATH)/WrongAnimal.hpp $(INC_PATH)/WrongCat.hpp
SRC_PATH = source
OBJ_PATH = obj
INC_PATH = include
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
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)"Successfully created the executable ./poly" $(WHITE)"
	
clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)
	@echo "$(BLUE)Sucessfully cleaned $(WHITE)"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean