NAME_SERVER = server
NAME_CLIENT = client
CC = gcc

# FLAGS = -Wall -Werror -Wextra

DIR_LIBFT = libft/
LIBFT = libft/libft.a

HEADER = minitalk.h

MINITALK_CLIENT = client.c
MINITALK_SERVER = server.c

SOURCES_LIBFT = $(addprefix $(DIR_LIBFT), $(LIBFT))

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(MINITALK_SERVER) $(LIBFT)
	@$(CC) $(FLAGS) $(MINITALK_SERVER) $(LIBFT) -o $(NAME_SERVER)
	@echo "server is ready to use"

$(NAME_CLIENT): $(MINITALK_CLIENT) $(LIBFT)
	@$(CC) $(FLAGS) $(MINITALK_CLIENT) $(LIBFT) -o $(NAME_CLIENT)
	@echo "client is ready to use"

$(LIBFT) :
	$(MAKE) -C $(DIR_LIBFT)

bonus: all
	@echo "minitalk with bonuses is ready to use"

fclean:
	@rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY : all re fclean bonus
