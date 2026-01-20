CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
LDFLAGS = 
RM = rm -rf

SRCS = main.cpp Bureaucrat.cpp Form.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = form

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(NAME)

%.o:	%.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	@echo "deleting binary files..."
	@$(RM) $(OBJS)

fclean: clean
	@echo "deleting executable"
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
