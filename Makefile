NAME_C = client
NAME_S = server

SRC_S = server.c	
OBJ_S = $(SRC_S:.c=.o)
SRC_C = client.C
OBJ_C = $(SRC_C:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

all: $(NAME_C)
all: $(NAME_S)

%.o: %.c
	@$(CC) -c $(CFLAGS) $?

$(NAME_C): $(OBJ_C) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_C) $(LIBFT) -o $(NAME_C)
$(NAME_S): $(OBJ_S) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_S) $(LIBFT) -o $(NAME_S)


$(LIBFT):
	@make -C libft

clean:
	@rm -fr $(OBJ_S) $(OBJ_C)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME_C) $(NAME_S)
	@make fclean -C libft
		
re: fclean all

.PHONY: all clean fclean re