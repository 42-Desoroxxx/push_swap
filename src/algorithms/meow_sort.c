/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meow_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:58:07 by llage             #+#    #+#             */
/*   Updated: 2025/04/02 21:58:07 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	meow_sort(struct s_stacks *stacks)
{
	bring_to_top(&stacks->stack_a, 0);
	push(&stacks->stack_b, &stacks->stack_a);
	if (stacks->stack_a.size == 5)
	{
		bring_to_top(&stacks->stack_a, 1);
		push(&stacks->stack_b, &stacks->stack_a);
	}
	three_sort(stacks);
	push(&stacks->stack_a, &stacks->stack_b);
	if (stacks->stack_a.capacity == 5)
		push(&stacks->stack_a, &stacks->stack_b);
}
