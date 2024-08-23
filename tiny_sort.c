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
	
	//if not sorted, do this movements unil sorted
	while (!is_sorted(a))
	{
		if (a->nbr > a->next->nbr)
			sa(a);
		else
			ra(a);
	}
}
