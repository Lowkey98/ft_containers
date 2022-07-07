CC = c++
SRC = main.cpp vector.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = vector

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: clean all
