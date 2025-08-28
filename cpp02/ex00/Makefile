# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/27 10:24:27 by ybouryal          #+#    #+#              #
#    Updated: 2025/08/27 10:24:34 by ybouryal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
LDFLAGS = 
RM = rm -rf

SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = fixed

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
