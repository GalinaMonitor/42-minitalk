NAME_SERVER = server
NAME_CLIENT = client
CC = gcc

# FLAGS = -Wall -Werror -Wextra

DIR_LIBFT = libft/libft/
LIBFT = libft/libft/libft.a

HEADER = minitalk.h

MINITALK_CLIENT = client.c service.c
MINITALK_SERVER = server.c

SOURCES_LIBFT = $(addprefix $(DIR_LIBFT), $(LIBFT))

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(LIBFT) $(MINITALK_SERVER)
	@$(CC) $(FLAGS) $(MINITALK_SERVER) $(LIBFT) -o $(NAME_SERVER)
	@echo "server is ready to use"

$(NAME_CLIENT): $(LIBFT) $(MINITALK_CLIENT)
	@$(CC) $(FLAGS) $(MINITALK_CLIENT) $(LIBFT) -o $(NAME_CLIENT)
	@echo "client is ready to use"

$(LIBFT) :
	$(MAKE) -C $(DIR_LIBFT)

bonus: all
	@echo "minitalk with bonuses is ready to use"

fclean:
	$(MAKE) fclean -C $(DIR_LIBFT)
	@rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all


.PHONY : all re fclean bonus
