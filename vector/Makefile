CC = c++
SRC = main.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3
NAME = vector

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: clean all
