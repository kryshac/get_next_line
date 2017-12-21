NAME	= get
COM		= gcc
FLAGS	= -Wall -Wextra -Werror
SRC		= main.c get_next_line.c
OBJ		= $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(COM) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ): %.o: %.c
	$(COM) -c $(FLAGS) $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
