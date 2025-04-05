/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_printer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:19:35 by llage             #+#    #+#             */
/*   Updated: 2025/04/05 23:11:37 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_operation(const char stack_name, char *operation)
{
	if (stack_name == 0)
		ft_printf("%s\n", operation);
	else
		ft_printf("%s%c\n", operation, stack_name);
}
