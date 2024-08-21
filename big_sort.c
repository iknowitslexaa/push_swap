/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneiva-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:03:57 by aneiva-d          #+#    #+#             */
/*   Updated: 2024/08/21 18:12:34 by aneiva-d         ###   ########.fr       */
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
	//This next loop will prepare the stacks for the big sort.
	while (stacklen-- > 3 && is_stack_sorted(*a))
	{
	}
}
