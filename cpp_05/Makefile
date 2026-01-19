NAME = bureaucrat

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++20

SRC = main.cpp Bureaucrat.cpp
HEADERS = $(INC_PATH)/Bureaucrat.hpp
SRC_PATH = source
OBJ_PATH = obj
INC_PATH = include
OBJ = $(SRC:%.cpp=$(OBJ_PATH)%.o)

all: $(NAME)

$(OBJ_PATH);
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp $(HEADERS) | $(OBJ_PATH) 
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)"Successfully created the executable ./bureaucrat" $(WHITE)"
clean: 
	rm -f $(OBJ)
	rm -rf $(OBJ_PATH)
	echo "$(BLUE)Successfully cleaned! $(WHITE)"
fclean: clean
	rm -f $(NAME)

re: fclean all

WHITE = \e[0m
BLUE = \e[34m
GREEN = \e[32m

.PHONY: all clean re fclean