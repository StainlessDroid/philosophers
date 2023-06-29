# Output Colors
CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

# Global Config
NAME		= philo
SRC 		= philo.c utils.c messages.c
OS			= $(shell uname)

OBJS			= $(SRC:.c=.o)
CFLAGS			= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)

	@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
	gcc $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created ✓${CLR_RMV}"

$(OBJS): $(SRC)
		$(CC) $(CFLAGS) -c $(SRC)

debug: compile_lib
	@echo "$(GREEN)--DEBUG MODE--\nCompilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
	$(CC) $(CFLAGS) -g $(SRC) -o $(NAME) -fsanitize=address,undefined
	@echo "$(GREEN)$(NAME) created ✓${CLR_RMV}"

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

norme:
		@norminette $(SRC) $(HEADER)

re: fclean all

.PHONY: all re clean fclean