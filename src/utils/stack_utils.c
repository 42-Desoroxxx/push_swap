/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:56:05 by llage             #+#    #+#             */
/*   Updated: 2025/03/27 08:56:43 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void fill_stacks(struct s_stacks *stacks, const size_t capacity, char *argv[])
{
	size_t i;

	i = capacity;
	while (i)
		stacks->stack_a.values[stacks->stack_a.size++] = ft_atoi(argv[i--]);
}

struct s_stacks init_stacks(const size_t capacity, char *argv[])
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
	fill_stacks(&stacks, capacity, argv);
	return (stacks);
}

void free_stacks(const struct s_stacks *stacks)
{
	free(stacks->stack_a.values);
	free(stacks->stack_b.values);
}