NAME = harlfilter

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++20
HEADERS = $(INC_PATH)/Harl.hpp
SRC = main.cpp Harl.cpp
SRC_PATH = source
OBJ_PATH = obj
INC_PATH = include
OBJ = $(SRC:%.cpp=$(OBJ_PATH)/%.o)

all: $(NAME)
	

$(OBJ_PATH): 
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp $(HEADERS) | $(OBJ_PATH) 
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "Successfully created the executable"
	
clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)
	@echo Sucessfully cleaned

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean