

NAME = ex01
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Serializer/Serializer.cpp \
	   main.cpp

OBJS = $(SRCS:.cpp=.o)
HEADERS = Serializer/Serializer.h

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