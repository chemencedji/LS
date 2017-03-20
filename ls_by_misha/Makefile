# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mihail <mihail@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/07 02:00:01 by mgolban           #+#    #+#              #
#    Updated: 2017/02/20 19:21:09 by ichemenc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
LIBRARY = libft

all: $(NAME)

$(NAME):
	make -C $(LIBRARY)
	$(CC) $(CFLAGS) -c $(SRC) -I $(LIBRARY)
	$(CC) $(OBJ) -L $(LIBRARY) -lft -o $(NAME)

.PHONY: clean

clean:
	make -C $(LIBRARY) clean
	/bin/rm -rf $(OBJ)
	@echo "Delete C object files"

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(LIBRARY)/libft.a
	@echo "Delete $(NAME)"
	@echo "Delete $(LIBRARY)/libft.a"

re: fclean all
