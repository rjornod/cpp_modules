NAME = account

CC = c++ --std=c++98
FLAGS = -Wall -Wextra -Werror 

SRC = Account.cpp tests.cpp
SRC_PATH = source
OBJ_PATH = obj
OBJ = $(SRC:%.cpp=$(OBJ_PATH)/%.o)

all: $(NAME)
	@echo "Successfully created the executable"

$(OBJ_PATH): 
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp | $(OBJ_PATH) 
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
 
clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)
	@echo Sucessfully cleaned

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean