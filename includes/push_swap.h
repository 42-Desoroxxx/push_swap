/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 08:55:32 by llage             #+#    #+#             */
/*   Updated: 2025/02/13 04:50:58 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <libft.h>
# include <ft_printf.h>

typedef struct s_stack
{
	int		*values;
	size_t	size;
	size_t	capacity;
	char	name;
}	t_stack;

#endif