NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror
MAIN = src/push_swap.c
SRC_DIR = src
OBJ_DIR = obj
SRC = already_sorted.c chunk_sort_left.c \
		chunk_sort_right.c operations.c push.c reverse_rotate.c \
		rotate.c small_sort_A.c small_sort_B.c \
		stack_init_fill.c stack_utils.c swap.c \

LIBFT = libft/libft.a
OBJECTS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

HEAD = ./include/push_swap.h

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@cc $(FLAGS) -c $< -o $@

$(NAME): $(OBJECTS) $(LIBFT) $(MAIN)
	@$(CC) $(FLAGS) $(MAIN) $(OBJECTS) -o $@ -L./libft -lft
	@echo "Built $(NAME)"

$(LIBFT):
	@$(MAKE) -C libft -f Makefile all
	@$(MAKE) -C libft -f Makefile clean

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Cleaned object files"

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C libft -f Makefile fclean
	@echo "Fully cleaned project"

re: fclean all

.PHONY: all clean fclean re