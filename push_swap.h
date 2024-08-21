/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneiva-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:08:19 by aneiva-d          #+#    #+#             */
/*   Updated: 2024/08/20 17:13:04 by aneiva-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <../libft/inc/libft.h>

typedef struct s_stack
{
	int		nbr;
	int		position;
	int		push_cost;
	bool		above_median;
	bool		cheapest;
	struct s_stack *target_node;
	struct s_stack *next;
	struct s_stack *prev;
}	t_stack;

#endif
