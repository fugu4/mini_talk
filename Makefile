CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME_CLIENT = client
NAME_SERVER = server

SRCS_CLIENT = client.c
SRCS_SERVER = server.c
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME_CLIENT) $(NAME_SERVER)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o $(NAME_SERVER)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all
