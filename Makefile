NAME_SERVER = server
NAME_CLIENT = client
LIBFT = ./libft/libft.a
SRC_SERVER = server.c
SRC_CLIENT = client.c
INC = -I include -I libft
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	make -C libft

$(NAME_SERVER): $(SRC_SERVER)
	$(CC) $(CFLAGS) $(INC) -o $@ $^ $(LIBFT)

$(NAME_CLIENT): $(SRC_CLIENT)
	$(CC) $(CFLAGS) $(INC) -o $@ $^ $(LIBFT)

clean:
	make clean -C libft
	rm -f *.o

fclean: clean
	make fclean -C libft
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all