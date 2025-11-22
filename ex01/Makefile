CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

ifeq ($(gdb),1)
	CXXFLAGS += -g
endif

NAME = Span
SRCS = main.cpp Span.cpp
HEADERS = Span.hpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
