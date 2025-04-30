/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 01:48:11 by llage             #+#    #+#             */
/*   Updated: 2025/04/06 01:53:51 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <limits.h>

bool	are_chars_valid(char *argv[])
{
	size_t	i;
	size_t	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (!argv[i][j])
			return (false);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
					&& argv[i][j] != '+' && argv[i][j] != '-')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	has_spaces(char *argv[])
{
	size_t	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_strchr(argv[i], ' ') != NULL)
			return (true);
		i++;
	}
	return (false);
}

bool	contains_duplicates(const struct s_stack *stack)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size)
		{
			if (i != j && stack->values[i] == stack->values[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool	contains_out_of_range_values(const struct s_stack *stack)
{
	size_t	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->values[i] < INT_MIN || stack->values[i] > INT_MAX)
			return (true);
		i++;
	}
	return (false);
}
