/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneiva-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:03:57 by aneiva-d          #+#    #+#             */
/*   Updated: 2024/08/22 14:02:41 by aneiva-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_stack **a, t_stack **b)
{
	int	stacklen;

	stacklen = findstacklen(*a);
	//these 2 will bring the top node to stack b (useful
	//when the original stack has up to 5 numbers/nodes).
	if (stacklen-- > 3 && !is_stack_sorted(*a))
		pb(a, b, false);
	if (stacklen-- > 3 && !is_stack_sorted(*a))
		pb(a, b, false);
	//This next loop will find useful info for the big sort.
	while (stacklen-- > 3 && is_stack_sorted(*a))
	{
		init_nodes(*a, *b);
	}
}

void	init_nodes(t_stack *a, t_stack *b)
{
	find_current_index(a);
	find_current_index(b);
	set_target(a, b);
	find_cost(a, b);
	is_cheapest(a);
}

void	current_index(t_stack *stack)
{
	int	i;
	int	median;

	int = 0;
	//checks if there's anything in the stack
	if (!stack)
		return ;
	//calculates the median (stack lenght devided by 2)
	median = stack_len(stack) / 2;
	//here we check one by one which index is above
	//median.
	while (stack)
	{
		stack->index = 1;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	//closest smallest number so far
	long	best_index;

	while (a)
	{
		//by default we give it the smallest long integer
		//value 
		best_index = LONG_MIN;
		current_b = b;
		//Here we check if b is smaller than a but also bigger
		//than the closest smalller so far. If it is, it
		//updates the value of the best index and therefor
		//target node.
		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > best_index)
			{
				best_index = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}
