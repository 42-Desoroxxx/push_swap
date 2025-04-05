/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meow_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 22:48:45 by llage             #+#    #+#             */
/*   Updated: 2025/03/30 22:48:45 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	three_sort(struct s_stacks *stacks)
{
	const long long	top = stacks->stack_a.values[stacks->stack_a.size - 1];
	const long long	middle = stacks->stack_a.values[stacks->stack_a.size - 2];
	const long long	bottom = stacks->stack_a.values[stacks->stack_a.size - 3];

	if (top > middle && middle > bottom)
	{
		rotate(&stacks->stack_a);
		swap(&stacks->stack_a);
	}
	else if (top > middle && top > bottom && middle < bottom)
		rotate(&stacks->stack_a);
	else if (top < middle && top > bottom)
		reverse_rotate(&stacks->stack_a);
	else if (top > middle && middle < bottom)
		swap(&stacks->stack_a);
	else if (top < bottom && middle > bottom)
	{
		reverse_rotate(&stacks->stack_a);
		swap(&stacks->stack_a);
	}
}
