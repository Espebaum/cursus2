NAME = harlFilter
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors -g
SRCS = main.cpp Harl.cpp
OBJS = $(SRCS:.cpp=.o)


$(NAME) : $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

%.o:%.cc
	$(CXX) $(CXXFLAGS) $< -c

all : $(NAME)

clean :	
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY = all clean fclean re