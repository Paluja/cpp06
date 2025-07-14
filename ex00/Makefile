

NAME = ex00
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = ScalarConverter/ScalarConverter.cpp \
	   main.cpp

OBJS = $(SRCS:.cpp=.o)
HEADERS = ScalarConverter/ScalarConverter.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re