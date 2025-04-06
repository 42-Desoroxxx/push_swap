/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 08:55:12 by llage             #+#    #+#             */
/*   Updated: 2025/04/06 01:53:51 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_usage(char *argv[])
{
	ft_printf("Usage: %s <value 0> <value 1> ...\n", argv[0]);
	ft_printf("or Usage: %s <\"value0 value1 ...\">\n", argv[0]);
	ft_printf("with NO duplicate values\n");
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	struct s_stacks	stacks;

	if (argc < 2 || (argc > 2 && has_spaces(argv)))
		print_usage(argv);
	stacks = init_stacks(argc - 1, argv);
	if (contains_duplicates(&stacks.stack_a))
	{
		ft_printf("Error: Stack contains duplicate values\n");
		free_stacks(&stacks);
		print_usage(argv);
	}
	if (!is_sorted(&stacks.stack_a) && stacks.stack_a.size > 1)
	{
		if (stacks.stack_a.size == 2)
			swap(&stacks.stack_a);
		else if (stacks.stack_a.size == 3)
			three_sort(&stacks);
		else if (stacks.stack_a.size <= 5)
			meow_sort(&stacks);
		else
			butterfly_sort(&stacks);
	}
	free_stacks(&stacks);
}
