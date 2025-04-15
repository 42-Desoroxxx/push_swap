/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 08:55:32 by llage             #+#    #+#             */
/*   Updated: 2025/04/06 01:53:51 by llage            ###   ########.fr       */
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

void			three_sort(struct s_stacks *stacks);
void			meow_sort(struct s_stacks *stacks);
void			butterfly_sort(struct s_stacks *stacks);

// Utils

void			print_usage_then_exit(char *argv[]);

bool			are_chars_valid(char *argv[]);
bool			has_spaces(char *argv[]);
bool			contains_duplicates(const struct s_stack *stack);
bool			contains_out_of_range_values(const struct s_stack *stack);

void			bring_to_top(struct s_stack *stack, const long long value);
bool			is_sorted(const struct s_stack *stack);

struct s_stacks init_stacks(const size_t capacity, char *argv[]);
void			free_stacks(const struct s_stacks *stacks);
size_t			get_index(const struct s_stack *stack, const int value);

// Operations

void			print_operation(const char stack_name, char *operation);

void			push(struct s_stack *target, struct s_stack *source);

void			swap(const struct s_stack *stack);
void			swap_stacks(const struct s_stacks *stacks);

void			rotate(const struct s_stack *stack);
void			rotate_stacks(const struct s_stacks *stacks);
void			reverse_rotate(const struct s_stack *stack);
void			reverse_rotate_stacks(const struct s_stacks *stacks);

#endif
