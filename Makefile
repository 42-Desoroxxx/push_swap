# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 22:55:02 by llage             #+#    #+#              #
#    Updated: 2025/04/22 06:21:22 by llage            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all bonus clean fclean re fast refast

GREEN = \033[1;32m
BLUE = \033[1;34m
RED = \033[1;31m
BLACK = \033[1;30m
RESET = \033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
DEPS = includes
SRC = src
OBJ = obj

SRCS := src/push_swap.c src/operations/operations_printer.c \
		src/operations/push_operations.c src/operations/rotate_operations.c \
		src/operations/swap_operations.c src/utils/stack_utils.c \
		src/utils/algorithm_utils.c src/algorithms/three_sort.c \
		src/algorithms/meow_sort.c src/algorithms/butterfly_sort.c \
		src/utils/parse_utils.c src/utils/error_utils.c
OBJS := $(patsubst $(SRC)/%,$(OBJ)/%,$(SRCS:.c=.o))

all: $(NAME)

Libft/Libft.a:
	@$(MAKE) -s -C Libft

$(OBJ)/%.o: $(SRC)/%.c $(DEPS)
	@mkdir -p $(@D)
	@echo "$(BLUE)Compiling$(RESET) $<..."
	@$(CC) $(CFLAGS) -I$(DEPS) -ILibft/includes -c $< -o $@

$(NAME): $(OBJS) Libft/Libft.a
	@echo "$(GREEN)Linking$(RESET) $@..."
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)Done!$(RESET)"

bonus: all

clean:
	@echo "$(RED)Cleaning$(RESET) object files..."
	@rm -rf $(OBJ)
	@$(MAKE) -s -C Libft clean

fclean: clean
	@echo "$(RED)Removing$(RESET) $(NAME)..."
	@rm -f $(NAME)
	@$(MAKE) -s -C Libft fclean

re: fclean
	@$(MAKE) --no-print-directory all
