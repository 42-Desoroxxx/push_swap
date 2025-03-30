/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 04:08:40 by llage             #+#    #+#             */
/*   Updated: 2025/03/30 04:08:40 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	bring_to_top(const struct s_stack *stack, const long long value)
{
	size_t index;

	index = get_index(stack, value);
	while (stack->values[stack->size - 1] != value)
	{
		if (index > (stack->size / 2) - 1)
			rotate((stack));
		else
			reverse_rotate((stack));
	}
}