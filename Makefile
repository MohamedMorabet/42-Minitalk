CC = cc

# CFLAGS = -Wall -Wextra -Werror

NAME_CLIENT = client

NAME_SERVER = server

AR = ar rcs

SRC_CLIENT = client.c \
		utils.c \
		printf/ft_printf.c \
		printf/num_functions.c \
		printf/str_functions.c 
	
SRC_SERVER = server.c \
		utils.c \
		printf/ft_printf.c \
		printf/num_functions.c \
		printf/str_functions.c \


OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

OBJ_SERVER = $(SRC_SERVER:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(NAME_SERVER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re