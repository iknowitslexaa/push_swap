/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_move_a_n_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneiva-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:22:24 by aneiva-d          #+#    #+#             */
/*   Updated: 2024/08/22 18:04:18 by aneiva-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	//This will check which cheapest is set to true.
	cheapest_node = get_cheapest(*a);
	//if both the cheaspest node and the target node
	//above the median, we just rotate the stacks.
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rr(a, b, cheapest_node);
	//if it's below the median we reverse rotate the stacks
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
		rrr(a, b, cheapest_node);
	prep
}
