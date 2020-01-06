NAME = n-puzzle

SRCS =	main.cpp Taquin.cpp State.cpp List.cpp
OBJS = $(SRCS:.cpp=.o)

CXX = clang++
CXXFLAGS = -std=c++98 -Ofast -Wall -Wextra -Werror #-fsanitize=address 
LDFLAGS = -Ofast -Wall -Wextra -Werror #-fsanitize=address 

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean all
