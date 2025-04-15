/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:59:53 by llage             #+#    #+#             */
/*   Updated: 2025/04/15 20:00:02 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_usage_then_exit(char *argv[])
{
	ft_fprintf(STDERR_FILENO, "Usage: %s <int> <int> ...\n", argv[0]);
	ft_fprintf(STDERR_FILENO, "or Usage: %s <\"int int ...\">\n", argv[0]);
	ft_fprintf(STDERR_FILENO, "with NO duplicate and only digits that may be prefixed with + or -\n");
	exit(EXIT_FAILURE);
}