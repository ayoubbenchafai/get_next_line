NAME= get_next_line.a
CC= cc
CFLAGS= -Wall -Wextra -Werror

SRC= get_next_line.c get_next_line_utils.c
OBJ= $(SRC:.c=.o)

All: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -o $@ -c $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)