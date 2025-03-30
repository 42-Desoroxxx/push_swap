/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 08:55:32 by llage             #+#    #+#             */
/*   Updated: 2025/03/19 01:03:53 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <libft.h>
# include <ft_printf.h>

typedef struct s_stack
{
	char		name;
	size_t		capacity;
	size_t		size;
	long long	*values;
}	t_stack;

typedef struct s_stacks
{
	t_stack	stack_a;
	t_stack	stack_b;
}	t_stacks;

// Algorithms

void butterfly(struct s_stacks *stacks);

// Utils

void print_ops();

void	bring_to_top(const struct s_stack *stack, const long long value);

struct s_stacks init_stacks(const size_t capacity, char *argv[]);
void free_stacks(const struct s_stacks *stacks);
size_t get_index(const struct s_stack *stack, const int value);

// Operations

void	print_operation(const char stack_name, char *operation);

void	push(struct s_stack *target, struct s_stack *source);

void	swap(const struct s_stack *stack);
void	swap_stacks(const struct s_stacks *stacks);

void	rotate(const struct s_stack *stack);
void	rotate_stacks(const struct s_stacks *stacks);
void	reverse_rotate(const struct s_stack *stack);
void	reverse_rotate_stacks(const struct s_stacks *stacks);

#endif
