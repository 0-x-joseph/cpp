CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
LDXXFLAGS = 
RM = rm -rf

SRCS = main.cpp BitcoinExchange.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = btc

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(LDXXFLAGS) $(OBJS) -o $(NAME)

%.o:	%.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	@echo "deleting binary files..."
	@$(RM) $(OBJS)

fclean: clean
	@echo "deleting executable"
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
