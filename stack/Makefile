CC = clang++
SRC = main.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = stack
FLAGS_DEBUG = --std=c++98 -Wall -Wextra -Werror -fsanitize=address -g3

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: clean all
