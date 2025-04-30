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

_Noreturn void	fatal_error(void)
{
	ft_fprintf(STDERR_FILENO, "Error\n");
	exit(EXIT_FAILURE);
}
