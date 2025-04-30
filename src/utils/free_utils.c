/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:46:39 by llage             #+#    #+#             */
/*   Updated: 2025/04/30 17:46:39 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i] != NULL)
		free(split[i++]);
	free(split);
}
