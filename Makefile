NAME = n-puzzle

SRCS =	main.cpp Taquin.cpp State.cpp List.cpp
OBJS = $(SRCS:.cpp=.o)

CXX = clang++
FLAGS = -std=c++98 -Ofast -Wall -Wextra -Werror -I./ #-fsanitize=address 

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean all
