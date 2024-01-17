NAME = philo

CFLAGS = cc -g -Wall -Wextra -Werror

SRC = philosopher.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CFLAGS) -c $< -o $@


all: $(NAME)

$(NAME): $(OBJ)
	@$(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re