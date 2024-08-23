/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneiva-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:20:00 by aneiva-d          #+#    #+#             */
/*   Updated: 2024/08/22 16:23:17 by aneiva-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		//if the best_index is still the same number we assigned
		//previously than we haven't find a number smaller than a
		//meaning we need to sety the target to the biggest number.
		if (best_index == LONG_MIN)
			a->target_node = find_max(b);
		//Otherwise we set it to our target_node variable and
		//move to the next the next a node.
		else
			a->target_node = target_node;
		a = a->next;
	}
}

//this function finds the push cost which is the sum of the
//amount of rotations it would take for a to be on top plus
//the amont of rotations it takes for the target node to be
//on top
static void	find_cost(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median)
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

//This function uses the push_data that we just calculated
//and goes through all of the nodes and searches for the
//cheapest node.
void	is_cheapest(t_stack *stack)
{
	long		cheapest_value;
	t_stack		*cheapest_node;

	//normal check
	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes(t_stack *a, t_stack *b)
{
	find_current_index(a);
	find_current_index(b);
	set_target(a, b);
	find_cost(a, b);
	is_cheapest(a);
}
