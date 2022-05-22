NAME = container

SRCS = helloworld.cpp
OBJS = ${SRCS:.cpp=.o}

.cpp.o:
	c++ ${FLAGS} -c $< -o ${<:.cpp=.o}

FLAGS = -std=c++98 -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all