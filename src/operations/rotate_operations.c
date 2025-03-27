/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 02:01:40 by llage             #+#    #+#             */
/*   Updated: 2025/03/27 08:35:39 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void internal_rotate(const struct s_stack *stack, const bool reverse)
{
	size_t i;
	int    temp;

	if (stack->size <= 1)
		return;
	if (reverse)
	{
		temp = stack->values[0];
		i = -1;
		while (++i < stack->size - 1)
			stack->values[i] = stack->values[i + 1];
		stack->values[stack->size - 1] = temp;
	}
	else
	{
		temp = stack->values[stack->size - 1];
		i = stack->size;
		while (--i > 0)
			stack->values[i] = stack->values[i - 1];
		stack->values[0] = temp;
	}
}

void rotate(const struct s_stack *stack)
{
	internal_rotate(stack, false);
	if (stack->size <= 1)
		return;
	print_operation(stack->name, "r");
}

void rotate_stacks(const struct s_stacks *stacks)
{
	internal_rotate(&stacks->stack_a, false);
	internal_rotate(&stacks->stack_b, false);
	print_operation(0, "rr");
}

void reverse_rotate(const struct s_stack *stack)
{
	internal_rotate(stack, true);
	if (stack->size <= 1)
		return;
	print_operation(stack->name, "rr");
}

void reverse_rotate_stacks(const struct s_stacks *stacks)
{
	internal_rotate(&stacks->stack_a, true);
	internal_rotate(&stacks->stack_b, true);
	print_operation(0, "rrr");
}
