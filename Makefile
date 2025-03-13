# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 22:55:02 by llage             #+#    #+#              #
#    Updated: 2025/02/05 05:46:22 by llage            ###   ########.fr        #
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
FASTFLAGS = -Ofast -march=native -flto
NAME = push_swap
DEPS = includes
SRC = src
OBJ = obj

SRCS := $(shell find $(SRC) -name "*.c")
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
	@$(CC) $(CFLAGS) $^ -o $@ -Llibft -lft
	@echo "$(GREEN)Done!$(RESET)"

bonus: all

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

fast: CFLAGS += $(FASTFLAGS)
fast:
	@echo "$(BLACK)MAKING THE $(RED)ULTIMATE$(BLACK) APP FORM$(RESET)"
	@$(MAKE) --no-print-directory CFLAGS="$(CFLAGS)"

refast: fclean
	@$(MAKE) fast --no-print-directory
