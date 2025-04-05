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

// true if an arg has spaces between digits
bool	has_spaces(char *argv[])
{
	size_t	i;

	i = 0;
	while (argv[i] != NULL)
	{
		ft_printf("%s\n", argv[i]);
		if (ft_strchr(argv[i], ' ') != NULL)
			return (false);
		i++;
	}
	return (true);
}