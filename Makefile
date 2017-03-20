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

ck:
		gcc -Wall -Werror -Wextra -g *.c -L libft/ -lft

fclean: clean
		/bin/rm -f $(NAME)
			/bin/rm -f $(LIBRARY)/libft.a
				@echo "Delete $(NAME)"
					@echo "Delete $(LIBRARY)/libft.a"

re: fclean all
