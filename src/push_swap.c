/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 08:55:12 by llage             #+#    #+#             */
/*   Updated: 2025/02/13 04:51:26 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static struct s_stacks init_stacks(const int capacity)
{
	struct s_stacks stacks;

	stacks.stack_a.name = 'a';
	stacks.stack_a.capacity = capacity;
	stacks.stack_a.size = 0;
	stacks.stack_a.values = ft_calloc(capacity, sizeof(int));

	stacks.stack_b.name = 'b';
	stacks.stack_b.capacity = capacity;
	stacks.stack_b.size = 0;
	stacks.stack_b.values = ft_calloc(capacity, sizeof(int));

	return (stacks);
}

static void free_stacks(struct s_stacks *stacks)
{
	free(stacks->stack_a.values);
	free(stacks->stack_b.values);
}

static void fill_stacks(struct s_stacks *stacks, int argc, char *argv[])
{
	int i;

	i = 1;
	while (i < argc)
	{
		stacks->stack_a.values[stacks->stack_a.size++] = ft_atoi(argv[i]);
		i++;
	}
}

static void print_stack(const struct s_stack *stack)
{
	size_t i;

	ft_printf("Stack %c:\n", stack->name);
	i = stack->size;
	while (i)
		ft_printf("%d\n", stack->values[--i]);
}

int	main(int argc, char *argv[])
{
	struct s_stacks stacks;

	if (argc < 2)
	{
		ft_printf("Usage: %s <value 0> <value 1> ...\n", argv[0]);
		return (1);
	}
	stacks = init_stacks(argc - 1);
	fill_stacks(&stacks, argc, argv);
	ft_printf("Stack A Size: %d\n", stacks.stack_a.size);
	ft_printf("Stack B Size: %d\n", stacks.stack_b.size);
	print_stack(&stacks.stack_a);
	print_stack(&stacks.stack_b);

	swap(&stacks.stack_a);
	print_stack(&stacks.stack_a);

	rotate(&stacks.stack_a);
	print_stack(&stacks.stack_a);

	reverse_rotate(&stacks.stack_a);
	print_stack(&stacks.stack_a);

	push(stacks.stack_b, stacks.stack_a);
	print_stack(&stacks.stack_a);
	print_stack(&stacks.stack_b);

	free_stacks(&stacks);
}
