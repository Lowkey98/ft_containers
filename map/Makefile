CC = c++
SRC = main.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = map

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: clean all
