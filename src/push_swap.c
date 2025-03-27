/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 08:55:12 by llage             #+#    #+#             */
/*   Updated: 2025/03/27 08:37:26 by llage            ###   ########.fr       */
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

static void free_stacks(const struct s_stacks *stacks)
{
	free(stacks->stack_a.values);
	free(stacks->stack_b.values);
}

static void fill_stacks(struct s_stacks *stacks, int argc, char *argv[])
{
	int i;

	i = argc;
	while (i > 1)
		stacks->stack_a.values[stacks->stack_a.size++] = ft_atoi(argv[--i]);
}

// static void print_stack(const struct s_stack *stack)
// {
// 	size_t i;
//
// 	ft_printf("Stack %c:\n", stack->name);
// 	i = stack->size;
// 	while (i)
// 		ft_printf("%d\n", stack->values[--i]);
// 	ft_printf("\n");
// }

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
	free_stacks(&stacks);
}
