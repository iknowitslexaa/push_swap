/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneiva-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:48:55 by aneiva-d          #+#    #+#             */
/*   Updated: 2024/08/21 16:57:46 by aneiva-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_stack **a)
{
	t_stack	*big_node;

	//we're gonna look for the biggest nbr in the
	//stack. If it's at the top of the stack, we're
	//gonna rotate the stack (a);
	big_node = find_max(*a);
	if (big_node == *a)
		ra(a, false);
	//if it's at the second position tho, we're gonna
	//bring it to last
	else if ((*a)->next == big_node)
		rra(a, false);
	//the if the firt number is bigger than the second
	//we're gonna swap them.
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}
