/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneiva-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:44:54 by aneiva-d          #+#    #+#             */
/*   Updated: 2024/08/22 14:20:36 by aneiva-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

bool	is_stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack->next;
	}
	return (true);
}

int	stack_len(t_stack *a)
{
	int	i;

	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}
