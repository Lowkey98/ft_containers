CC = c++
SRC = main.cpp
HEADER = iterator.hpp vector.hpp
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = vector

all: $(NAME)

$(NAME): $(SRC) $(HEADER)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: clean all
