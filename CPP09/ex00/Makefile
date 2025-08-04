NAME = btc

CPPFLAGS = -Wall -Werror -Wextra

SRC = main.cpp\
	BitcoinExchange.cpp\

OBJ = $(SRC:.cpp=.o)
OBJ_DIR = build
OBJ_PATH = $(OBJ:%=$(OBJ_DIR)/%)

all: $(NAME)

$(NAME): $(OBJ_PATH)
		@c++ $(CPPFLAGS) $(OBJ_PATH) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
		@mkdir -p $(OBJ_DIR)
		@c++ $(CPPFLAGS) -c $< -o $@

clean:
		@rm -rf $(OBJ_DIR)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re