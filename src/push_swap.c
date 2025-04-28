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

#include <push_swap.h>

int	main(int argc, char *argv[])
{
	struct s_stacks	stacks;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	if (argc > 2 && has_spaces(argv) && !are_chars_valid(argv))
		fatal_error();
	stacks = init_stacks(argc - 1, argv);
	if (contains_duplicates(&stacks.stack_a))
	{
		free_stacks(&stacks);
		fatal_error();
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
