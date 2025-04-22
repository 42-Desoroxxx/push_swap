# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 22:55:02 by llage             #+#    #+#              #
#    Updated: 2025/04/22 06:35:42 by llage            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus

GREEN = \033[1;32m
BLUE = \033[1;34m
RED = \033[1;31m
RESET = \033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 -ffast-math -march=native -flto
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

libft/libft.a:
	@$(MAKE) -s -C libft

$(OBJ)/%.o: $(SRC)/%.c $(DEPS)
	@mkdir -p $(@D)
	@echo "$(BLUE)Compiling$(RESET) $<..."
	@$(CC) $(CFLAGS) -I$(DEPS) -Ilibft/includes -c $< -o $@

$(NAME): $(OBJS) libft/libft.a
	@echo "$(GREEN)Linking$(RESET) $@..."
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)Done!$(RESET)"

clean:
	@echo "$(RED)Cleaning$(RESET) object files..."
	@rm -rf $(OBJ)
	@$(MAKE) -s -C libft clean

fclean: clean
	@echo "$(RED)Removing$(RESET) $(NAME)..."
	@rm -f $(NAME)
	@$(MAKE) -s -C libft fclean

re: fclean
	@$(MAKE) --no-print-directory all

bonus: all
