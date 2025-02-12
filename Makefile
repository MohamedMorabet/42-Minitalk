CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = client

NAME_SERVER = server

AR = ar rcs

SRC_CLIENT = client.c \
		utils.c \
		utils2.c \
		printf/ft_printf.c \
		printf/num_functions.c \
		printf/str_functions.c 
	
SRC_SERVER = server.c \
		utils.c \
		utils2.c \
		printf/ft_printf.c \
		printf/num_functions.c \
		printf/str_functions.c \

SRC_CLIENT_BONUS = bonus/client_bonus.c \
		bonus/utils_bonus.c \
		bonus/utils2_bonus.c \
		printf/ft_printf.c \
		printf/num_functions.c \
		printf/str_functions.c

SRC_SERVER_BONUS = bonus/server_bonus.c \
		bonus/utils_bonus.c \
		bonus/utils2_bonus.c \
		printf/ft_printf.c \
		printf/num_functions.c \
		printf/str_functions.c


OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

OBJ_SERVER = $(SRC_SERVER:.c=.o)

OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)

OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)

all: $(NAME) $(NAME_SERVER)

$(NAME): $(OBJ_CLIENT) minitalk.h
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(NAME)

$(NAME_SERVER): $(OBJ_SERVER) minitalk.h
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(NAME_SERVER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS) bonus/minitalk_bonus.h
	$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) -o $(NAME)
	$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) -o $(NAME_SERVER)

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re