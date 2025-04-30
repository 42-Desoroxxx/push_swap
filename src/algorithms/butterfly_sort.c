/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:42:36 by llage             #+#    #+#             */
/*   Updated: 2025/04/06 01:25:07 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static long long	find_next(const struct s_stack *stack, size_t start,
	const size_t end)
{
	size_t		i;
	size_t		next_from_top;
	long long	next_from_bottom;

	next_from_bottom = -1;
	next_from_top = 0;
	i = 0;
	while (i < stack->size)
	{
		if (stack->values[i] >= (long long) start
			&& stack->values[i] <= (long long) end)
		{
			next_from_top = i;
			if (next_from_bottom == -1)
				next_from_bottom = i;
		}
		i++;
	}
	if (next_from_bottom == -1)
		return (-1);
	if ((stack->size - 1) - next_from_top <= (size_t) next_from_bottom + 1)
		return (stack->values[next_from_top]);
	return (stack->values[next_from_bottom]);
}

static void	push_chunk(struct s_stacks *stacks, size_t start, const size_t end)
{
	const size_t	midpoint = (end + start) / 2;

	while (find_next(&stacks->stack_a, start, end) != -1)
	{
		bring_to_top(&stacks->stack_a,
			find_next(&stacks->stack_a, start, end));
		push(&stacks->stack_b, &stacks->stack_a);
		if (stacks->stack_b.values[stacks->stack_b.size - 1]
			<= (long long) midpoint)
			rotate(&stacks->stack_b);
	}
}

static void	push_chunks(struct s_stacks *stacks, const size_t chunk_number)
{
	const size_t	chunk_size = stacks->stack_a.size / chunk_number;
	const size_t	remainder = stacks->stack_a.size % chunk_number;
	size_t			i;

	i = 0;
	while (i < chunk_number)
	{
		if (i != chunk_number - 1 || remainder == 0)
			push_chunk(stacks, i * chunk_size, (i * chunk_size) + chunk_size);
		else
			push_chunk(stacks, i * chunk_size,
				(i * chunk_size) + chunk_size + remainder);
		i++;
	}
}

static void	finish(struct s_stacks *stacks)
{
	while (stacks->stack_b.size > 0)
	{
		bring_to_top(&stacks->stack_b, (long long) stacks->stack_b.size - 1);
		push(&stacks->stack_a, &stacks->stack_b);
	}
}

void	butterfly_sort(struct s_stacks *stacks)
{
	if (stacks->stack_a.size <= 100)
		push_chunks(stacks, 5);
	else
		push_chunks(stacks, 11);
	finish(stacks);
}
