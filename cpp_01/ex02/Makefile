NAME = brain

CC = c++
FLAGS = -Wall -Wextra -Werror 

SRC = main.cpp
SRC_PATH = source
OBJ_PATH = obj
OBJ = $(SRC:%.cpp=$(OBJ_PATH)/%.o)

all: $(NAME)

$(OBJ_PATH): 
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp | $(OBJ_PATH) 
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