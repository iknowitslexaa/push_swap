/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_move_a_n_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneiva-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:22:24 by aneiva-d          #+#    #+#             */
/*   Updated: 2024/08/29 18:12:26 by aneiva-d         ###   ########.fr       */
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
	//This is to make sure that both our cheapest node and
	//target node are on top of the stack, by doing rotate
	//or reverse rotate operations until the node we want is
	//on top.
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(a, cheapest_node->target_node, 'b');
	//then we'll push our a node to b.
	pb(b, a, false);
}

void	prep_for_push(t_stack **stack, t_stack*top_node, char stack_name)
{
	while (*stack != top_node)
	{
		//If the stack is a, then we'll do the moves that rotate a.
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		//else we'll do it for b.
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
