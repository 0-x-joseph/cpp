CC = c++
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = 
RM = rm -rf

SRCS = main.cpp Serializer.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = serializer

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
