/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:52:10 by llage             #+#    #+#             */
/*   Updated: 2025/03/27 08:04:09 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push(struct s_stack *target, struct s_stack *source)
{
	if (source->size == 0)
		return ;
	target->values[target->size++] = source->values[source->size - 1];
	source->size--;
	print_operation(target->name, "p");
}
