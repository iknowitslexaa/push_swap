/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneiva-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:31:34 by aneiva-d          #+#    #+#             */
/*   Updated: 2024/08/21 15:22:40 by aneiva-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//we use structures to create the stacks. In this case 
//I'm using a structure calles t_stack that will include
//all of the necessary info.
int	main(int argc, char **argv)
{
	//Using the structure to create stack a and stack b.
	t_stack	*a;
	t_stack *b;

	//this function will check if there's at least 1 usable
	//argument and call the split function if the numbers are
	//presented in the form of a string.
	argv = check_input_error(argc, argv);
	//this function creates the a stack.
	stacks.head_a = create_list_a(argc, argv);
	stacks.head_b = NULL;
	//this loop will sort the stack, if necessary.
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) = 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
	free_stack;
	return (0);
}
