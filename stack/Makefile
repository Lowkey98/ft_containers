CC = c++
SRC = main.cpp
HEADER = stack.hpp
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = stack

all: $(NAME)

$(NAME): $(SRC) $(HEADER)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: clean all