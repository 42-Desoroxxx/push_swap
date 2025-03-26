/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 02:01:40 by llage             #+#    #+#             */
/*   Updated: 2025/03/19 02:01:40 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	internal_rotate(const struct s_stack *stack, const bool reverse,const bool print)
{
	int

	if (stack->size <= 1)
		return ;


	if (print)
		print_operation(stack->name, "r");
}

void	rotate(const struct s_stack *stack)
{
	internal_rotate(stack, true);
}

void	rotate_stacks(const struct s_stacks *stacks)
{
	internal_rotate(&stacks->stack_a, false);
	internal_rotate(&stacks->stack_b, false);

	print_operation(0, "rr");
}