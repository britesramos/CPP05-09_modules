NAME = intern

CPPFLAGS = -Wall -Werror -Wextra -std=c++17

SRC = main.cpp\
	Bureaucrat.cpp\
	AForm.cpp\
	ShrubberyCreationForm.cpp\
	PresidentialPardonForm.cpp\
	RobotomyRequestForm.cpp\
	Intern.cpp\

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
		@rm -f *_shrubbery

re: fclean all

.PHONY: all clean fclean re