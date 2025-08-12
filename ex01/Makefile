CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
LDFLAGS = 
RM = rm -rf

SRCS = megaphone.cpp
OBJS = $(SRCS:.c=.o)

NAME = megaphone

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(NAME)

%.o:	%.c
	$(CC) $(CFLAGS) -c $<

clean:
	@echo "deleting binary files..."
	@$(RM) $(OBJS)

fclean: clean
	@echo "deleting executable"
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
