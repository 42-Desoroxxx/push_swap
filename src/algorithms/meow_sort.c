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

void meow_sort(struct s_stacks *stacks)
{
	ft_printf("size - 1 = %d\n", stacks->stack_a.size - 1);
	ft_printf("size - 2 = %d\n", stacks->stack_a.size - 2);
	rotate(&stacks->stack_a);
	ft_printf("size - 1 = %d\n", stacks->stack_a.size - 1);
	ft_printf("size - 2 = %d\n", stacks->stack_a.size - 2);
	exit(0);
	while (!is_sorted(&stacks->stack_a))
	{
		rotate(&stacks->stack_a);
		if (stacks->stack_a.values[stacks->stack_a.size - 1] > stacks->stack_a.values[stacks->stack_a.size - 2])
			swap(&stacks->stack_a);
	}
}
