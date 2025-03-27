/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:09:10 by llage             #+#    #+#             */
/*   Updated: 2025/03/19 01:09:10 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	internal_swap(const struct s_stack *stack, const bool print)
{
	int	tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->values[stack->size - 1];
	stack->values[stack->size - 1] = stack->values[stack->size - 2];
	stack->values[stack->size - 2] = tmp;

	if (print)
		print_operation(stack->name, "s");
}

void	swap(const struct s_stack *stack)
{
	internal_swap(stack, true);
}

void	swap_stacks(const struct s_stacks *stacks)
{
	internal_swap(&stacks->stack_a, false);
	internal_swap(&stacks->stack_b, false);

	print_operation(0, "ss");
}