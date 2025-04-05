/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:56:05 by llage             #+#    #+#             */
/*   Updated: 2025/03/27 08:56:43 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	normalize_stack(const struct s_stack *stack, long long *temp)
{
	int			rank;
	size_t		i;
	size_t		j;

	i = 0;
	while (i < stack->size)
	{
		rank = 0;
		j = 0;
		while (j < stack->size)
		{
			if (stack->values[j] < stack->values[i])
				rank++;
			j++;
		}
		temp[i] = rank;
		i++;
	}
	i = 0;
	while (i < stack->size)
	{
		stack->values[i] = temp[i];
		i++;
	}
}

static void	fill_stacks(struct s_stacks *stacks, size_t capacity,
						char *argv[], const bool one_arg)
{
	char		**temp;
	long long	*normal_temp;

	if (one_arg)
	{
		temp = ft_split(argv[1], ' ');
		while (capacity)
		{
			stacks->stack_a.values[stacks->stack_a.size++]
				= ft_atoi(temp[capacity - 1]);
			capacity--;
		}
		free(temp);
	}
	else
	{
		while (capacity)
			stacks->stack_a.values[stacks->stack_a.size++]
				= ft_atoi(argv[capacity--]);
	}
	normal_temp = ft_calloc(capacity, sizeof(long long));
	if (normal_temp == NULL)
		return ;
	normalize_stack(&stacks->stack_a, normal_temp);
	free(normal_temp);
}

struct s_stacks	init_stacks(size_t capacity, char *argv[])
{
	const bool		one_arg = capacity == 1;
	struct s_stacks	stacks;
	char			**temp;

	if (one_arg)
	{
		temp = ft_split(argv[1], ' ');
		capacity = 0;
		while (temp[capacity] != NULL)
			capacity++;
		free(temp);
	}
	stacks.stack_a.name = 'a';
	stacks.stack_a.capacity = capacity;
	stacks.stack_a.size = 0;
	stacks.stack_a.values = ft_calloc(capacity, sizeof(long long));
	stacks.stack_b.name = 'b';
	stacks.stack_b.capacity = capacity;
	stacks.stack_b.size = 0;
	stacks.stack_b.values = ft_calloc(capacity, sizeof(long long));
	fill_stacks(&stacks, capacity, argv, one_arg);
	return (stacks);
}

void	free_stacks(const struct s_stacks *stacks)
{
	free(stacks->stack_a.values);
	free(stacks->stack_b.values);
}

size_t	get_index(const struct s_stack *stack, const int value)
{
	size_t i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->values[i] == value)
			return (i);
		i++;
	}
	return (0);
}
