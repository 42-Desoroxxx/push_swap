/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:42:36 by llage             #+#    #+#             */
/*   Updated: 2025/03/27 09:42:36 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void push_chunk(struct s_stacks *stacks, size_t start, const size_t end)
{
	const size_t midpoint = (end + start) / 2;
	size_t left;

	left = end - start;
	while (left)
	{
		while (stacks->stack_a.values[stacks->stack_a.size - 1] < (long long) start || stacks->stack_a.values[stacks->stack_a.size - 1] > (long long) end)
			rotate(&stacks->stack_a); // TODO: Function to get the next one in the most efficient way

		push(&stacks->stack_b, &stacks->stack_a);

		if (stacks->stack_b.values[stacks->stack_a.size - 1] < (long long) midpoint)
			rotate(&stacks->stack_b);
		left--;
	}
}

static void push_chunks(struct s_stacks *stacks, const size_t chunk_number)
{
	(void) chunk_number;
	push_chunk(stacks, 4, 8);
}

void butterfly(struct s_stacks *stacks)
{
	push_chunks(stacks, 5);
}
