/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 08:55:32 by llage             #+#    #+#             */
/*   Updated: 2025/02/05 08:55:32 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_PUSH_H

# define SWAP_PUSH_H

# include "libft.h"
# include "ft_printf.h"

typedef struct s_stack
{
	int		*values;
	size_t	size;
	size_t	capacity;
} t_stack;

#endif