NAME = intern

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++20

SRC = Bureaucrat.cpp main.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
HEADERS = $(INC_PATH)/Bureaucrat.hpp $(INC_PATH)/AForm.hpp $(INC_PATH)/PresidentialPardonForm.hpp $(INC_PATH)/RobotomyRequestForm.hpp $(INC_PATH)/ShrubberyCreationForm.hpp $(INC_PATH)/Intern.hpp
SRC_PATH = source
OBJ_PATH = obj
INC_PATH = include
OBJ = $(SRC:%.cpp=$(OBJ_PATH)/%.o)

WHITE = \e[0m
BLUE = \e[34m
GREEN = \e[32m

all: $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp $(HEADERS) | $(OBJ_PATH) 
	$(CC) $(FLAGS) -I$(INC_PATH)  -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)"Successfully created the executable ./intern" $(WHITE)"
clean: 
	rm -f $(OBJ)
	rm -rf $(OBJ_PATH)
	@echo "$(BLUE)Successfully cleaned! $(WHITE)"
fclean: clean
	rm -f $(NAME)

re: fclean all

valgrind: $(NAME)
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean re fclean valgrind